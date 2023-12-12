//
// Created by synse on 12/11/23.
//

#ifndef MINECRAFTAPIERROR_H
#define MINECRAFTAPIERROR_H
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace MinecraftAuth {
    /**
     * @brief Represents an error response from a Minecraft API request.
     *
     * MinecraftApiError stores information received as an error response
     * from a Minecraft API request, including the request path, error type,
     * specific error, error message, and developer-specific message.
     */
    struct MinecraftApiError {
        std::string m_Path; ///< The path of the API request that resulted in an error.
        std::string m_ErrorType; ///< The type or category of the error.
        std::string m_Error; ///< Specific error code or identifier.
        std::string m_ErrorMessage; ///< Descriptive error message.
        std::string m_DeveloperMessage; ///< Developer-specific message providing additional context.

        /**
         * @brief Parse a JSON string to create a MinecraftApiError.
         *
         * @param jsonStr JSON string representing the Minecraft API error response.
         * @return The MinecraftApiError parsed from the JSON.
         */
        static MinecraftApiError FromJson(const std::string& jsonStr) {
            json j = json::parse(jsonStr);
            MinecraftApiError error;
            error.m_Path = j["path"];
            error.m_ErrorType = j["errorType"];
            error.m_Error = j["error"];
            error.m_ErrorMessage = j["errorMessage"];
            error.m_DeveloperMessage = j["developerMessage"];
            return error;
        }
    };
} // MinecraftAuth

#endif //MINECRAFTAPIERROR_H
