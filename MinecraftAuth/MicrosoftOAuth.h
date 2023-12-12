//
// Created by synse on 12/11/23.
//

#ifndef MICROSOFTOAUTH_H
#define MICROSOFTOAUTH_H
#include <string>

#include "Data/Account.h"
#include "Data/Responses/DeviceAuthorizationResponse.h"
#include "Data/Responses/XBLAuthenticationResponse.h"
#include "Data/Responses/XSTSAuthenticationResponse.h"
#include "Http/HttpEngine.h"

namespace MinecraftAuth {
    /**
     * @brief MicrosoftOAuth class for handling Microsoft OAuth flows.
     *
     * This class provides functionalities for Microsoft OAuth, including device
     * authentication, token retrieval, XBL authentication, XSTS authentication,
     * and Minecraft authentication.
     */
    class MicrosoftOAuth {
    public:
        // Constants
        static inline const std::string CLIENT_ID = "170105bd-9573-4222-b09c-6f24c3b77cd8";
        static inline const std::string TENANT = "consumers";

        static inline const std::string DEVICE_CODE_URL =
                "https://login.microsoftonline.com/" + TENANT + "/oauth2/v2.0/devicecode";
        static inline const std::string TOKEN_URL =
                "https://login.microsoftonline.com/" + TENANT + "/oauth2/v2.0/token";
        static inline const std::string XBL_AUTH_URL = "https://user.auth.xboxlive.com/user/authenticate";
        static inline const std::string XSTS_AUTH_URL = "https://xsts.auth.xboxlive.com/xsts/authorize";
        static inline const std::string MINECRAFT_XBOX_LOGIN_URL =
                "https://api.minecraftservices.com/authentication/login_with_xbox";
        static inline const std::string MINECRAFT_PROFILE_URL = "https://api.minecraftservices.com/minecraft/profile";

        // Functions
        /**
         * @brief Initiates device authentication flow.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @return AuthenticationResponse containing device authentication details.
         */
        static AuthenticationResponse DeviceAuth(const HttpEngine& engine);

        /**
         * @brief Starts the device authentication process.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @return DeviceAuthorizationResponse containing device authorization details.
         */
        static DeviceAuthorizationResponse StartDeviceAuth(const HttpEngine& engine);

        /**
         * @brief Checks the status of device authentication.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param deviceAuth DeviceAuthorizationResponse containing device authorization details.
         * @return AuthenticationResponse containing the access token upon successful authentication.
         */
        static AuthenticationResponse CheckDeviceAuth(const HttpEngine& engine,
                                                      const DeviceAuthorizationResponse& deviceAuth);

        /**
        * @brief Refreshes the Microsoft authentication using the provided refresh token.
        *
        * @param engine The HttpEngine used for making HTTP requests.
        * @param tokens MSTokens containing the refresh token.
        * @return AuthenticationResponse containing updated authentication details.
        */
        static AuthenticationResponse RefreshMicrosoftAuth(const HttpEngine& engine, const MSTokens& tokens);

        /**
         * @brief Logs in to a Minecraft account using Microsoft authentication details.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param msAuth AuthenticationResponse containing Microsoft authentication details.
         * @return Account representing the Minecraft account.
         */
        static Account LoginToAccount(const HttpEngine& engine, const AuthenticationResponse& msAuth);

        /**
         * @brief Validates the Minecraft account and refreshes the token if necessary.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param account Account to be validated and updated.
         */
        static void ValidateAccount(const HttpEngine& engine, Account& account);

        /**
         * @brief Refreshes the Minecraft access token for the given account.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param account Account for which the Minecraft token should be refreshed.
         */
        static void RefreshMinecraftToken(const HttpEngine& engine, Account& account);

        /**
         * @brief Refreshes the Microsoft access token for the given account.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param account Account for which the Microsoft token should be refreshed.
         */
        static void RefreshMicrosoftToken(const HttpEngine& engine, Account& account);

        /**
         * @brief Authenticates with Xbox Live (XBL) using the provided authentication token.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param authToken Authentication token used for XBL authentication.
         * @return XBLAuthenticationResponse containing XBL authentication details.
         */
        static XBLAuthenticationResponse AuthenticateWithXBL(const HttpEngine& engine, const std::string& authToken);

        /**
         * @brief Authenticates with Xbox Secure Token Service (XSTS) using XBL authentication details.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param auth XBLAuthenticationResponse containing XBL authentication details.
         * @return XSTSAuthenticationResponse containing XSTS authentication details.
         */
        static XSTSAuthenticationResponse AuthenticateWithXSTS(const HttpEngine& engine,
                                                               const XBLAuthenticationResponse& auth);

        /**
         * @brief Authenticates with Minecraft services using XBL and XSTS authentication details.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param xblAuth XBLAuthenticationResponse containing XBL authentication details.
         * @param xstsAuth XSTSAuthenticationResponse containing XSTS authentication details.
         * @return MinecraftAuthResponse containing Minecraft authentication details.
         */
        static MinecraftAuthResponse AuthenticateWithMinecraft(const HttpEngine& engine,
                                                               const XBLAuthenticationResponse& xblAuth,
                                                               const XSTSAuthenticationResponse& xstsAuth);

        /**
         * @brief Retrieves the Minecraft profile using the provided Minecraft authentication details.
         *
         * @param engine The HttpEngine used for making HTTP requests.
         * @param minecraftAuth MinecraftAuthResponse containing Minecraft authentication details.
         * @return MinecraftProfile representing the Minecraft profile.
         */
        static MinecraftProfile GetMinecraftProfile(const HttpEngine& engine,
                                                    const MinecraftAuthResponse& minecraftAuth);
    };
} // MinecraftAuth

#endif //MICROSOFTOAUTH_H
