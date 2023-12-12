//
// Created by synse on 12/11/23.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

#include "MinecraftProfile.h"
#include "Responses/AuthenticationResponse.h"
#include "Responses/MinecraftAuthResponse.h"

namespace MinecraftAuth {
    /**
     * @brief Represents Microsoft Account tokens.
     *
     * MSTokens stores Microsoft Account tokens including access token,
     * refresh token, and expiration timestamp.
     */
    class MSTokens {
    public:
        std::string m_AccessToken; ///< Microsoft Access Token.
        std::string m_RefreshToken; ///< Microsoft Refresh Token.
        long m_ExpiresAt{}; ///< Expiration timestamp.

        /**
         * @brief Default constructor for MSTokens.
         */
        MSTokens() = default;

        /**
         * @brief Constructor for MSTokens using AuthenticationResponse.
         *
         * @param auth AuthenticationResponse containing Microsoft tokens.
         */
        explicit MSTokens(const AuthenticationResponse& auth);
    };

    /**
     * @brief Represents Minecraft Account tokens.
     *
     * MCTokens stores Minecraft Account tokens including access token
     * and expiration timestamp.
     */
    class MCTokens {
    public:
        std::string m_AccessToken; ///< Minecraft Access Token.
        long m_ExpiresAt{}; ///< Expiration timestamp.

        /**
         * @brief Default constructor for MCTokens.
         */
        MCTokens() = default;

        /**
         * @brief Constructor for MCTokens using MinecraftAuthResponse.
         *
         * @param auth MinecraftAuthResponse containing Minecraft tokens.
         */
        explicit MCTokens(const MinecraftAuthResponse& auth);
    };

    /**
     * @brief Represents a Minecraft account.
     *
     * The Account class stores information about a Minecraft account,
     * including the username, UUID, and tokens for both Microsoft and Minecraft.
     */
    class Account {
    public:
        std::string m_Username; ///< Minecraft account username.
        std::string m_UUID; ///< Minecraft account UUID.
        MSTokens m_MSTokens; ///< Microsoft Account tokens.
        MCTokens m_MCTokens; ///< Minecraft Account tokens.

        /**
         * @brief Constructor for Account using MinecraftProfile, AuthenticationResponse, and MinecraftAuthResponse.
         *
         * @param mcProfile MinecraftProfile containing Minecraft account information.
         * @param msAuth AuthenticationResponse containing Microsoft Account tokens.
         * @param mcAuth MinecraftAuthResponse containing Minecraft Account tokens.
         */
        Account(const MinecraftProfile& mcProfile, const AuthenticationResponse& msAuth,
                const MinecraftAuthResponse& mcAuth);
    };
} // MinecraftAuth

#endif //ACCOUNT_H
