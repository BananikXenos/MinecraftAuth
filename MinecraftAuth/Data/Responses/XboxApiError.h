//
// Created by synse on 12/11/23.
//

#ifndef XBOXAPIERROR_H
#define XBOXAPIERROR_H
#include <string>
#include <nlohmann/json_fwd.hpp>
using json = nlohmann::json;

namespace MinecraftAuth {
    /**
     * @brief Represents an error response from Xbox APIs.
     *
     * XboxApiError stores information about errors returned from Xbox APIs,
     * including identity, error code (XErr), error message, and redirection URL.
     */
    struct XboxApiError {
        int m_Identity; ///< The identity associated with the error.
        long m_XErr; ///< The error code (XErr) indicating the type of error.
        std::string m_Message; ///< The error message describing the issue.
        std::string m_Redirect; ///< The URL to redirect to in case of an error.

        /**
         * @brief Parse a JSON string to create an XboxApiError instance.
         *
         * @param body JSON string representing the Xbox API error response.
         * @return The XboxApiError instance parsed from the JSON.
         */
        static XboxApiError FromJson(const std::string& body) {
            json j = json::parse(body);
            const int identity = j["Identity"];
            const long xErr = j["XErr"];
            const std::string& message = j["Message"];
            const std::string& redirect = j["Redirect"];
            return {identity, xErr, message, redirect};
        }
    };
} // MinecraftAuth

#endif //XBOXAPIERROR_H
