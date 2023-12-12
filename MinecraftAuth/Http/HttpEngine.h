//
// Created by synse on 12/11/23.
//

#ifndef HTTPENGINE_H
#define HTTPENGINE_H
#include <string>
#include <unordered_map>

#include "HttpResponse.h"

namespace MinecraftAuth {
    /**
     * @brief Interface for HTTP request handling.
     *
     * The HttpEngine class defines an interface for handling HTTP requests, including methods
     * for sending GET, POST (JSON and Form), and making generic requests. Implementations of
     * this interface provide the actual HTTP communication functionality.
     */
    class HttpEngine {
    public:
        /**
         * @brief Content types for HTTP requests.
         */
        static inline const std::string FORM_URL_ENCODED = "application/x-www-form-urlencoded";
        static inline const std::string JPPLICATION_JSON = "application/json";

        /**
         * @brief Virtual destructor for the HttpEngine class.
         */
        virtual ~HttpEngine() = default;

        /**
         * @brief Sends a GET request with optional headers and retrieves JSON response.
         *
         * @param url The URL for the GET request.
         * @param headers Optional headers to include in the request.
         * @return The HTTP response containing the JSON data.
         */
        [[nodiscard]] HttpResponse GetJson(const std::string& url,
                                           const std::unordered_map<std::string, std::string>& headers = {}) const;

        /**
         * @brief Sends a POST request with JSON body and optional headers.
         *
         * @param url The URL for the POST request.
         * @param body The JSON body to include in the request.
         * @param headers Optional headers to include in the request.
         * @return The HTTP response for the POST request.
         */
        [[nodiscard]] HttpResponse PostJson(const std::string& url, const std::string& body = {},
                                            const std::unordered_map<std::string, std::string>& headers = {}) const;

        /**
         * @brief Sends a POST request with form-encoded body and optional headers.
         *
         * @param url The URL for the POST request.
         * @param body The form-encoded body to include in the request.
         * @param headers Optional headers to include in the request.
         * @return The HTTP response for the POST request.
         */
        [[nodiscard]] HttpResponse PostForm(const std::string& url,
                                            const std::unordered_map<std::string, std::string>& body = {},
                                            const std::unordered_map<std::string, std::string>& headers = {}) const;

        /**
         * @brief Makes a generic HTTP request with specified method, URL, body, and headers.
         *
         * This method needs to be implemented by the concrete HTTP engine.
         *
         * @param method The HTTP method (e.g., GET, POST, etc.).
         * @param url The URL for the request.
         * @param body The body of the request.
         * @param headers Optional headers to include in the request.
         * @return The HTTP response for the generic request.
         */
        [[nodiscard]] virtual HttpResponse MakeRequest(const std::string& method, const std::string& url,
                                                       const std::string& body,
                                                       const std::unordered_map<std::string, std::string>& headers)
        const = 0;

        /**
         * @brief Checks if a request method requires a request body.
         *
         * @param method The HTTP method to check.
         * @return True if the method requires a request body, false otherwise.
         */
        static bool RequiresRequestBody(const std::string& method);
    };
} // MinecraftAuth

#endif //HTTPENGINE_H
