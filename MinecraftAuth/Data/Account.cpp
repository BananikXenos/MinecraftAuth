//
// Created by synse on 12/11/23.
//

#include "Account.h"

namespace MinecraftAuth {
    MSTokens::MSTokens(const AuthenticationResponse& auth) {
        m_AccessToken = auth.m_AccessToken;
        m_RefreshToken = auth.m_RefreshToken;

        const auto currentTime = std::chrono::system_clock::now();
        const auto expirationTime = currentTime + std::chrono::seconds(auth.expiresIn);
        m_ExpiresAt = std::chrono::duration_cast<std::chrono::milliseconds>(expirationTime.time_since_epoch()).
                count();
    }

    MCTokens::MCTokens(const MinecraftAuthResponse& auth) {
        m_AccessToken = auth.m_AccessToken;

        const auto currentTime = std::chrono::system_clock::now();
        const auto expirationTime = currentTime + std::chrono::seconds(auth.m_ExpiresIn);
        m_ExpiresAt = std::chrono::duration_cast<std::chrono::milliseconds>(expirationTime.time_since_epoch()).
                count();
    }

    Account::Account(const MinecraftProfile& mcProfile, const AuthenticationResponse& msAuth, const MinecraftAuthResponse& mcAuth) {
        m_Username = mcProfile.m_Name;
        m_UUID = mcProfile.GetUUID();
        m_MSTokens = MSTokens(msAuth);
        m_MCTokens = MCTokens(mcAuth);
    }


} // MinecraftAuth
