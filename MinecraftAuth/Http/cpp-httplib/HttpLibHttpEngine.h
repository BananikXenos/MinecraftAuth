//
// Created by synse on 12/11/23.
//

#ifndef HTTPLIBHTTPENGINE_H
#define HTTPLIBHTTPENGINE_H

#include "../HttpEngine.h"

namespace MinecraftAuth {
    /**
     * @brief HTTP engine implementation using the httplib library.
     *
     * The HttpLibHttpEngine class extends the HttpEngine interface and provides
     * an implementation using the httplib library for making HTTP requests.
     */
    class HttpLibHttpEngine final : public HttpEngine {
    public:
        ~HttpLibHttpEngine() override = default;

        /**
         * @brief Makes an HTTP request using the httplib library.
         *
         * @param method The HTTP method (e.g., GET, POST).
         * @param url The URL for the HTTP request.
         * @param body The request body for methods that support it.
         * @param headers Additional headers to include in the request.
         * @return The HttpResponse object representing the HTTP response.
         * @throws std::invalid_argument if the URL is in an invalid format.
         * @throws std::invalid_argument if the HTTP method is invalid.
         * @throws std::runtime_error if the HTTP request fails.
         */
        [[nodiscard]] HttpResponse MakeRequest(const std::string& method, const std::string& url,
                                               const std::string& body,
                                               const std::unordered_map<std::string, std::string>& headers)
        const override;
    };
} // MinecraftAuth

#endif //HTTPLIBHTTPENGINE_H
