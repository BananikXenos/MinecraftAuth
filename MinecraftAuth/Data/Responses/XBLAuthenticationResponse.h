//
// Created by synse on 12/11/23.
//

#ifndef XBLAUTHENTICATIONRESPONSE_H
#define XBLAUTHENTICATIONRESPONSE_H
#include <string>
#include <nlohmann/json_fwd.hpp>

using json = nlohmann::json;

namespace MinecraftAuth {
    /**
     * @brief Represents the response from authenticating with Xbox Live services.
     *
     * XBLAuthenticationResponse stores information obtained when authenticating
     * with Xbox Live services, including issue instant, expiration time, token,
     * and display claims.
     */
    struct XBLAuthenticationResponse {
        std::string m_IssueInstant; ///< The timestamp when the token was issued.
        std::string m_NotAfter; ///< The timestamp indicating when the token expires.
        std::string m_Token; ///< The authentication token from Xbox Live.
        json m_DisplayClaims; ///< Display claims associated with the user.

        /**
         * @brief Get the XUID (Xbox User ID) from the display claims.
         *
         * @return The Xbox User ID (XUID) extracted from the display claims.
         */
        [[nodiscard]] std::string GetXUID() const {
            return m_DisplayClaims["xui"][0]["uhs"];
        }

        /**
         * @brief Parse a JSON string to create an XBLAuthenticationResponse.
         *
         * @param body JSON string representing the Xbox Live authentication response.
         * @return The XBLAuthenticationResponse parsed from the JSON.
         */
        static XBLAuthenticationResponse FromJson(const std::string& body) {
            json j = json::parse(body);
            const std::string& issueInstant = j["IssueInstant"];
            const std::string& notAfter = j["NotAfter"];
            const std::string& token = j["Token"];
            const json& displayClaims = j["DisplayClaims"];
            return {issueInstant, notAfter, token, displayClaims};
        }
    };
} // MinecraftAuth

#endif //XBLAUTHENTICATIONRESPONSE_H
