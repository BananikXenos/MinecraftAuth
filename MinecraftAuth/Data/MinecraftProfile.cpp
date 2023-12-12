//
// Created by synse on 12/11/23.
//
#include "MinecraftProfile.h"

namespace MinecraftAuth {
    std::string MinecraftProfile::GetUUID() const noexcept(false) {
        if (m_Id.size() != 32) {
            throw std::runtime_error("Invalid UUID");
        }
        const std::string timeLow = m_Id.substr(0, 8);
        const std::string timeMid = m_Id.substr(8, 12);
        const std::string timeHighAndVersion = m_Id.substr(12, 16);
        const std::string variantAndSeq = m_Id.substr(16, 20);
        const std::string node = m_Id.substr(20, 32);
        return timeLow + "-" + timeMid + "-" + timeHighAndVersion + "-" + variantAndSeq + "-" + node;
    }

    MinecraftProfile MinecraftProfile::FromJson(const std::string& body)  {
        json j = json::parse(body);
        MinecraftProfile profile;
        profile.m_Id = j["id"];
        profile.m_Name = j["name"];
        profile.m_Skins = j["skins"];
        profile.m_Capes = j["capes"];
        return profile;
    }
} // MinecraftAuth
