//
// Created by synse on 12/11/23.
//

#ifndef XSTSAUTHENTICATIONRESPONSE_H
#define XSTSAUTHENTICATIONRESPONSE_H
#include <string>
#include <nlohmann/json_fwd.hpp>

using json = nlohmann::json;

namespace MinecraftAuth {
    /**
     * @brief Represents the response from XSTS (Xbox Secure Token Service) authentication.
     *
     * XSTSAuthenticationResponse stores information about the XSTS authentication response,
     * including issue instant, expiration time, authentication token, and display claims.
     */
    struct XSTSAuthenticationResponse {
        std::string m_IssueInstant; ///< The timestamp when the token was issued.
        std::string m_NotAfter; ///< The timestamp indicating when the token expires.
        std::string m_Token; ///< The XSTS authentication token.
        json m_DisplayClaims; ///< Additional claims associated with the authentication.

        /**
         * @brief Get the XUID (Xbox User ID) from the display claims.
         *
         * @return The Xbox User ID extracted from the display claims.
         */
        std::string GetXUID() {
            return m_DisplayClaims["xui"][0]["uhs"];
        }

        /**
         * @brief Parse a JSON string to create an XSTSAuthenticationResponse instance.
         *
         * @param jsonStr JSON string representing the XSTS authentication response.
         * @return The XSTSAuthenticationResponse instance parsed from the JSON.
         */
        static XSTSAuthenticationResponse FromJson(const std::string& jsonStr) {
            json j = json::parse(jsonStr);
            XSTSAuthenticationResponse response;
            response.m_IssueInstant = j["IssueInstant"];
            response.m_NotAfter = j["NotAfter"];
            response.m_Token = j["Token"];
            response.m_DisplayClaims = j["DisplayClaims"];
            return response;
        }
    };
} // MinecraftAuth

#endif //XSTSAUTHENTICATIONRESPONSE_H
