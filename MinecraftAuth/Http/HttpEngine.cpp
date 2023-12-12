//
// Created by synse on 12/11/23.
//

#include "HttpEngine.h"

#include "../Utils/StringUtils.h"
#include <sstream>
#include <iomanip>

namespace MinecraftAuth {
    HttpResponse HttpEngine::GetJson(const std::string& url,
                                     const std::unordered_map<std::string, std::string>& headers) const {
        std::unordered_map<std::string, std::string> newHeaders = headers;
        newHeaders["Content-Type"] = JPPLICATION_JSON;
        newHeaders["Accept"] = JPPLICATION_JSON;
        return MakeRequest("GET", url, {}, newHeaders);
    }

    HttpResponse HttpEngine::PostJson(const std::string& url, const std::string& body,
                                      const std::unordered_map<std::string, std::string>& headers) const {
        std::unordered_map<std::string, std::string> newHeaders = headers;
        newHeaders["Content-Type"] = JPPLICATION_JSON;
        newHeaders["Accept"] = JPPLICATION_JSON;
        return MakeRequest("POST", url, body, newHeaders);
    }

    std::string formEncode(const std::unordered_map<std::string, std::string>& query) {
        std::stringstream builder;
        for (const auto& [key, value]: query) {
            if (!builder.str().empty()) {
                builder << "&";
            }
            builder << key << "=" << value;
        }
        return builder.str();
    }

    HttpResponse HttpEngine::PostForm(const std::string& url, const std::unordered_map<std::string, std::string>& body,
                                      const std::unordered_map<std::string, std::string>& headers) const {
        std::unordered_map<std::string, std::string> newHeaders = headers;
        newHeaders["Content-Type"] = FORM_URL_ENCODED;
        const std::string bodyStr = formEncode(body);

        return MakeRequest("POST", url, bodyStr, newHeaders);
    }

    bool HttpEngine::RequiresRequestBody(const std::string& method) {
        return StringUtils::iequals(method, "POST") || StringUtils::iequals(method, "PUT") ||
               StringUtils::iequals(method, "PATCH") || StringUtils::iequals(method, "PROPPATCH") ||
               StringUtils::iequals(method, "REPORT");
    }
} // MinecraftAuth
