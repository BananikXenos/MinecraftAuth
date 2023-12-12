//
// Created by synse on 12/11/23.
//

#ifndef AUTHENTICATIONRESPONSE_H
#define AUTHENTICATIONRESPONSE_H
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace MinecraftAuth {
    /**
     * @brief Represents the response from an authentication request.
     *
     * AuthenticationResponse stores information received as a response
     * to an authentication request, including the token type, scope,
     * expiration time, access token, and refresh token.
     */
    struct AuthenticationResponse {
        std::string m_TokenType; ///< Type of the access token.
        std::string m_Scope; ///< Scope of the access token.
        int expiresIn; ///< Expiration time of the access token in seconds.
        std::string m_AccessToken; ///< Access token for authentication.
        std::string m_RefreshToken; ///< Refresh token for obtaining a new access token.

        /**
         * @brief Parse a JSON string to create an AuthenticationResponse.
         *
         * @param body JSON string representing the authentication response.
         * @return The AuthenticationResponse parsed from the JSON.
         */
        static AuthenticationResponse FromJson(const std::string& body) {
            json j = json::parse(body);
            const std::string& tokenType = j["token_type"];
            const std::string& scope = j["scope"];
            const int expiresIn = j["expires_in"];
            const std::string& accessToken = j["access_token"];
            const std::string& refreshToken = j["refresh_token"];
            return {tokenType, scope, expiresIn, accessToken, refreshToken};
        }
    };
} // MinecraftAuth

#endif //AUTHENTICATIONRESPONSE_H
