//
// Created by synse on 12/11/23.
//

#ifndef MINECRAFTAUTHRESPONSE_H
#define MINECRAFTAUTHRESPONSE_H

namespace MinecraftAuth {
    /**
     * @brief Represents the response from authenticating with Minecraft services.
     *
     * MinecraftAuthResponse stores information obtained when authenticating
     * with Minecraft services, including the authenticated username, roles,
     * access token, token type, and expiration duration.
     */
    struct MinecraftAuthResponse {
        std::string m_Username; ///< The authenticated username.
        std::vector<std::string> m_Roles; ///< List of roles associated with the user.
        std::string m_AccessToken; ///< The access token obtained during authentication.
        std::string m_TokenType; ///< The type of token (e.g., "Bearer").
        int m_ExpiresIn; ///< Duration (in seconds) until the access token expires.

        /**
         * @brief Parse a JSON string to create a MinecraftAuthResponse.
         *
         * @param body JSON string representing the Minecraft authentication response.
         * @return The MinecraftAuthResponse parsed from the JSON.
         */
        static MinecraftAuthResponse FromJson(const std::string& body) {
            json j = json::parse(body);
            const std::string& username = j["username"];
            const std::vector<std::string>& roles = j["roles"];
            const std::string& accessToken = j["access_token"];
            const std::string& tokenType = j["token_type"];
            const int expiresIn = j["expires_in"];
            return {username, roles, accessToken, tokenType, expiresIn};
        }
    };
} // MinecraftAuth

#endif //MINECRAFTAUTHRESPONSE_H
