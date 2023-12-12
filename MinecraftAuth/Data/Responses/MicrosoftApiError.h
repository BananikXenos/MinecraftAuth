//
// Created by synse on 12/11/23.
//

#ifndef MICROSOFTAPIERROR_H
#define MICROSOFTAPIERROR_H
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace MinecraftAuth {
    /**
     * @brief Represents an error response from a Microsoft API request.
     *
     * MicrosoftApiError stores information received as an error response
     * from a Microsoft API request, including error code, description, codes,
     * timestamp, trace ID, correlation ID, and an optional error URI.
     */
    struct MicrosoftApiError {
        std::string m_Error; ///< Error code or type.
        std::string m_ErrorDescription; ///< Description of the error.
        std::vector<int> m_ErrorCodes; ///< Error codes associated with the error.
        std::string m_timestamp; ///< Timestamp when the error occurred.
        std::string m_TraceId; ///< Unique identifier for tracing the error.
        std::string m_CorrelationId; ///< Correlation ID for associating multiple requests.
        std::string m_ErrorUri; ///< Optional URI providing more information about the error.

        /**
         * @brief Parse a JSON string to create a MicrosoftApiError.
         *
         * @param body JSON string representing the Microsoft API error response.
         * @return The MicrosoftApiError parsed from the JSON.
         */
        static MicrosoftApiError FromJson(const std::string& body) {
            json j = json::parse(body);
            const std::string& error = j["error"];
            const std::string& errorDescription = j["error_description"];
            const std::vector<int>& errorCodes = j["error_codes"];
            const std::string& timestamp = j["timestamp"];
            const std::string& traceId = j["trace_id"];
            const std::string& correlationId = j["correlation_id"];
            const std::string& errorUri = j["error_uri"];
            return {error, errorDescription, errorCodes, timestamp, traceId, correlationId, errorUri};
        }
    };
} // MinecraftAuth

#endif //MICROSOFTAPIERROR_H
