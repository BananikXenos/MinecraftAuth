//
// Created by synse on 12/11/23.
//

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
#include <string>
#include <utility>

namespace MinecraftAuth {
    /**
     * @brief Represents an HTTP response.
     *
     * The HttpResponse class encapsulates the details of an HTTP response, including
     * the status code, message, and the response body. It provides a convenient method
     * for deserializing the response body into a specified type using the FromJson method.
     */
    class HttpResponse {
    public:
        /**
         * @brief Constructor for HttpResponse.
         *
         * @param code The HTTP status code.
         * @param message The status message associated with the code.
         * @param body The response body as a string.
         */
        HttpResponse(int code, std::string message, std::string body);

        /**
         * @brief Deserializes the response body into the specified type.
         *
         * This method uses the FromJson method of the target type to convert the
         * response body from JSON to the specified type.
         *
         * @tparam T The type to deserialize the response body into.
         * @return An instance of type T populated with data from the response body.
         */
        template<typename T>
        T FromJson() {
            return T::FromJson(m_Body);
        }

        const int m_Code; ///< The HTTP status code.
        const std::string m_Message; ///< The status message associated with the code.
        const std::string m_Body; ///< The response body as a string.
    };
} // MinecraftAuth

#endif //HTTPRESPONSE_H
