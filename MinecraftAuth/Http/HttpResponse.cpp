//
// Created by synse on 12/12/23.
//

#include "HttpEngine.h"

namespace MinecraftAuth {
    HttpResponse::HttpResponse(const int code, std::string message, std::string body)
        : m_Code(code), m_Message(std::move(message)), m_Body(std::move(body)) {
    }
} // MinecraftAuth