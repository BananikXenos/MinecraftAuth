//
// Created by synse on 12/11/23.
//

#ifndef MINECRAFTPROFILE_H
#define MINECRAFTPROFILE_H

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace MinecraftAuth {

/**
 * @brief Represents a Minecraft player profile.
 *
 * MinecraftProfile stores information about a player's Minecraft profile,
 * including the player's UUID, name, skins, and capes.
 */
struct MinecraftProfile {
    std::string m_Id; ///< UUID of the Minecraft player.
    std::string m_Name; ///< Name of the Minecraft player.
    json m_Skins; ///< JSON object representing the player's skins.
    json m_Capes; ///< JSON object representing the player's capes.

    /**
     * @brief Get the UUID of the Minecraft player.
     *
     * @return The UUID of the player.
     * @throw std::runtime_error if the 'id' field is missing in the JSON.
     */
    [[nodiscard]] std::string GetUUID() const noexcept(false);

    /**
     * @brief Parse a JSON string to create a MinecraftProfile.
     *
     * @param body JSON string representing the Minecraft player profile.
     * @return The MinecraftProfile parsed from the JSON.
     */
    static MinecraftProfile FromJson(const std::string& body);
};

} // MinecraftAuth

#endif //MINECRAFTPROFILE_H
