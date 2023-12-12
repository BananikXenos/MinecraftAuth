//
// Created by synse on 12/11/23.
//

#include "MicrosoftOAuth.h"

#include <httplib.h>
#include <thread>

#include "Data/Responses/MicrosoftApiError.h"
#include "Data/Responses/MinecraftApiError.h"
#include "Data/Responses/XboxApiError.h"

namespace MinecraftAuth {
    AuthenticationResponse MicrosoftOAuth::DeviceAuth(const HttpEngine& engine) {
        const DeviceAuthorizationResponse deviceAuth = StartDeviceAuth(engine);
        std::cout << deviceAuth.m_Message << std::endl;
        const int64_t expiresAt = std::chrono::duration_cast<std::chrono::seconds>(
                                      std::chrono::system_clock::now().time_since_epoch()).count() + deviceAuth.
                                  m_ExpiresIn;
        while (std::chrono::duration_cast<std::chrono::seconds>(
                   std::chrono::system_clock::now().time_since_epoch()).count() < expiresAt) {
            std::this_thread::sleep_for(std::chrono::seconds(deviceAuth.m_Interval));
            AuthenticationResponse auth = CheckDeviceAuth(engine, deviceAuth);
            if (auth.m_AccessToken.empty()) {
                continue;
            }
            return auth;
        }
        throw std::runtime_error("Device login timed out");
    }

    DeviceAuthorizationResponse MicrosoftOAuth::StartDeviceAuth(const HttpEngine& engine) {
        const std::unordered_map<std::string, std::string> body = {
            {"client_id", CLIENT_ID},
            {"scope", "XboxLive.signin offline_access"},
        };
        return engine.PostForm(DEVICE_CODE_URL, body).FromJson<DeviceAuthorizationResponse>();
    }

    AuthenticationResponse MicrosoftOAuth::CheckDeviceAuth(const HttpEngine& engine,
                                                           const DeviceAuthorizationResponse& deviceAuth) {
        const std::unordered_map<std::string, std::string> body = {
            {"grant_type", "urn:ietf:params:oauth:grant-type:device_code"},
            {"client_id", CLIENT_ID},
            {"device_code", deviceAuth.m_DeviceCode},
        };
        HttpResponse response = engine.PostForm(TOKEN_URL, body);

        if (response.m_Code != 200) {
            const auto [m_Error, m_ErrorDescription, m_ErrorCodes, m_timestamp, m_TraceId, m_CorrelationId, m_ErrorUri] = response.FromJson<MicrosoftApiError>();
            if (m_Error == "authorization_pending") {
                return {};
            }
            throw std::runtime_error(m_ErrorDescription);
        }

        return response.FromJson<AuthenticationResponse>();
    }

    AuthenticationResponse MicrosoftOAuth::RefreshMicrosoftAuth(const HttpEngine& engine, const MSTokens& tokens) {
        const std::unordered_map<std::string, std::string> body = {
            {"grant_type", "refresh_token"},
            {"client_id", CLIENT_ID},
            {"scope", "XboxLive.signin offline_access"},
            {"refresh_token", tokens.m_RefreshToken},
        };
        HttpResponse response = engine.PostForm(TOKEN_URL, body);

        if (response.m_Code != 200) {
            const auto [m_Error, m_ErrorDescription, m_ErrorCodes, m_timestamp, m_TraceId, m_CorrelationId, m_ErrorUri] = response.FromJson<MicrosoftApiError>();
            throw std::runtime_error(m_ErrorDescription);
        }

        return response.FromJson<AuthenticationResponse>();
    }

    Account MicrosoftOAuth::LoginToAccount(const HttpEngine& engine, const AuthenticationResponse& msAuth) {
        XBLAuthenticationResponse xblAuth = AuthenticateWithXBL(engine, msAuth.m_AccessToken);
        XSTSAuthenticationResponse xstsAuth = AuthenticateWithXSTS(engine, xblAuth);

        MinecraftAuthResponse minecraftAuth = AuthenticateWithMinecraft(engine, xblAuth, xstsAuth);

        MinecraftProfile profile = GetMinecraftProfile(engine, minecraftAuth);

        return {profile, msAuth, minecraftAuth};
    }

    void MicrosoftOAuth::ValidateAccount(const HttpEngine& engine, Account& account) {
        if (std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() < account.m_MCTokens.m_ExpiresAt) {
            RefreshMinecraftToken(engine, account);
        }
    }

    void MicrosoftOAuth::RefreshMinecraftToken(const HttpEngine& engine, Account& account) {
        if (std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() < account.m_MSTokens.m_ExpiresAt) {
            RefreshMicrosoftToken(engine, account);
        }

        const XBLAuthenticationResponse xblAuth = AuthenticateWithXBL(engine, account.m_MSTokens.m_AccessToken);
        const XSTSAuthenticationResponse xstsAuth = AuthenticateWithXSTS(engine, xblAuth);

        account.m_MCTokens = MCTokens(AuthenticateWithMinecraft(engine, xblAuth, xstsAuth));
    }

    void MicrosoftOAuth::RefreshMicrosoftToken(const HttpEngine& engine, Account& account) {
        account.m_MSTokens = MSTokens(RefreshMicrosoftAuth(engine, account.m_MSTokens));
    }

    XBLAuthenticationResponse MicrosoftOAuth::AuthenticateWithXBL(const HttpEngine& engine,
                                                                  const std::string& authToken) {
        const json bodyJson = {
            {
                "Properties", {
                    {"AuthMethod", "RPS"},
                    {"SiteName", "user.auth.xboxlive.com"},
                    {"RpsTicket", "d=" + authToken},
                }
            },
            {"RelyingParty", "http://auth.xboxlive.com"},
            {"TokenType", "JWT"},
        };
        const std::string body = bodyJson.dump();
        HttpResponse response = engine.PostJson(XBL_AUTH_URL, body);

        if (response.m_Code != 200) {
            const auto [m_Identity, m_XErr, m_Message, m_Redirect] = response.FromJson<XboxApiError>();
            throw std::runtime_error(m_Message);
        }

        return response.FromJson<XBLAuthenticationResponse>();
    }

    XSTSAuthenticationResponse MicrosoftOAuth::AuthenticateWithXSTS(const HttpEngine& engine,
                                                                    const XBLAuthenticationResponse& auth) {
        const json bodyJson = {
            {
                "Properties", {
                    {"SandboxId", "RETAIL"},
                    {"UserTokens", {auth.m_Token}},
                }
            },
            {"RelyingParty", "rp://api.minecraftservices.com/"},
            {"TokenType", "JWT"},
        };
        const std::string body = bodyJson.dump();
        HttpResponse response = engine.PostJson(XSTS_AUTH_URL, body);

        if (response.m_Code != 200) {
            const auto [m_Identity, m_XErr, m_Message, m_Redirect] = response.FromJson<XboxApiError>();
            if (m_XErr == 2148916233L) {
                std::cout <<
                        "[DevLogin] You don't have an XBoxLive account. Please login to Minecraft at least once in the Vanilla launcher."
                        << std::endl;
            } else if (m_XErr == 2148916235L) {
                std::cout << "[DevLogin] XBoxLive is not available or banned in your country." << std::endl;
            } else if (m_XErr == 2148916236L || m_XErr == 2148916237L) {
                std::cout << "[DevLogin] Your account needs adult verification. (South Korea)" << std::endl;
            } else if (m_XErr == 2148916238L) {
                std::cout << "[DevLogin] Your account is a child account and must be added to a Family by an adult." <<
                        std::endl;
            } else if (!m_Message.empty()) {
                std::cout << "[DevLogin] Unknown XSTS Login error: " << m_Message << std::endl;
            } else {
                std::cout << "[DevLogin] Unknown XSTS Login error: " << m_XErr << std::endl;
            }
            throw std::runtime_error(m_Message);
        }

        return response.FromJson<XSTSAuthenticationResponse>();
    }

    MinecraftAuthResponse MicrosoftOAuth::AuthenticateWithMinecraft(const HttpEngine& engine,
                                                                    const XBLAuthenticationResponse& xblAuth,
                                                                    const XSTSAuthenticationResponse& xstsAuth) noexcept
        (false
        ) {
        const json bodyJson = {
            {"identityToken", "XBL3.0 x=" + xblAuth.GetXUID() + ";" + xstsAuth.m_Token},
            {"ensureLegacyEnabled", true},
        };
        const std::string body = bodyJson.dump();
        HttpResponse response = engine.PostJson(MINECRAFT_XBOX_LOGIN_URL, body);

        if (response.m_Code != 200) {
            const auto [m_Path, m_ErrorType, m_Error, m_ErrorMessage, m_DeveloperMessage] = response.FromJson<MinecraftApiError>();
            throw std::runtime_error(m_ErrorMessage);
        }

        return response.FromJson<MinecraftAuthResponse>();
    }

    MinecraftProfile MicrosoftOAuth::GetMinecraftProfile(const HttpEngine& engine,
                                                         const MinecraftAuthResponse& minecraftAuth) {
        HttpResponse response = engine.GetJson(MINECRAFT_PROFILE_URL, {
                                                   {"Authorization", "Bearer " + minecraftAuth.m_AccessToken},
                                               });

        if (response.m_Code != 200) {
            const auto [m_Path, m_ErrorType, m_Error, m_ErrorMessage, m_DeveloperMessage] = response.FromJson<
                MinecraftApiError>();
            throw std::runtime_error(m_ErrorMessage);
        }

        return response.FromJson<MinecraftProfile>();
    }
} // MinecraftAuth
