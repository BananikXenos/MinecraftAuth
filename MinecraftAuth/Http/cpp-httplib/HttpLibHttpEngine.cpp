//
// Created by synse on 12/11/23.
//

#include "HttpLibHttpEngine.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

namespace MinecraftAuth {
    struct UrlComponents {
        std::string protocol;
        std::string host;
        int port{};
        std::string path;
    };

    /**
     * @brief Splits a URL into its components.
     *
     * @param url The URL to split.
     * @return UrlComponents object containing protocol, host, port, and path.
     * @throws std::invalid_argument if the URL is in an invalid format.
     */
    UrlComponents SplitUrl(const std::string& url) {
        const std::regex urlRegex(R"((https?)://([^:/]+)(?::(\d+))?(/.*)?)");

        if (std::smatch match; std::regex_match(url, match, urlRegex)) {
            UrlComponents components;
            components.protocol = match[1].str();
            components.host = match[2].str();
            components.port = match[3].str().empty()
                                  ? (components.protocol == "https" ? 443 : 80)
                                  : std::stoi(match[3].str());
            components.path = match[4].str();
            return components;
        }

        // Handle invalid URL
        throw std::invalid_argument("Invalid URL format");
    }

    HttpResponse HttpLibHttpEngine::MakeRequest(const std::string& method, const std::string& url,
                                                const std::string& body,
                                                const std::unordered_map<std::string, std::string>& headers) const {
        const auto [protocol, host, port, path] = SplitUrl(url);

        httplib::SSLClient client(host, port);
        client.set_follow_location(true);

        httplib::Headers httplibHeaders;
        for (const auto& [key, value]: headers) {
            httplibHeaders.emplace(key, value);
        }

        httplib::Result result;
        if (method == "GET") {
            result = client.Get(path, httplibHeaders);
        } else if (method == "POST") {
            result = client.Post(path, httplibHeaders, body, "");
        } else {
            throw std::invalid_argument("Invalid HTTP method");
        }

        if (!result) {
            throw std::runtime_error("HTTP request failed");
        }

        const int code = result->status;
        const std::string message = result->reason;

        return {code, message, result->body};
    }
} // MinecraftAuth
