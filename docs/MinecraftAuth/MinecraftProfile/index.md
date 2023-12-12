title: MinecraftProfile
description: Represents a Minecraft player profile.
generator: doxide
---


# MinecraftProfile

**struct MinecraftProfile**



Represents a Minecraft player profile.

MinecraftProfile stores information about a player's Minecraft profile,
including the player's UUID, name, skins, and capes.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_Id](#m_Id) |  UUID of the Minecraft player. |
| [m_Name](#m_Name) |  Name of the Minecraft player. |
| [m_Skins](#m_Skins) |  JSON object representing the player's skins. |
| [m_Capes](#m_Capes) |  JSON object representing the player's capes. |

## Functions

| Name | Description |
| ---- | ----------- |
| [GetUUID](#GetUUID) | Get the UUID of the Minecraft player. |
| [FromJson](#FromJson) | Parse a JSON string to create a MinecraftProfile. |

## Variable Details

### m_Capes<a name="m_Capes"></a>

!!! variable "json m_Capes"

     JSON object representing the player's capes.

### m_Id<a name="m_Id"></a>

!!! variable "std::string m_Id"

     UUID of the Minecraft player.

### m_Name<a name="m_Name"></a>

!!! variable "std::string m_Name"

     Name of the Minecraft player.

### m_Skins<a name="m_Skins"></a>

!!! variable "json m_Skins"

     JSON object representing the player's skins.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static MinecraftProfile FromJson(const std::string&amp; body)"

    
    
    Parse a JSON string to create a MinecraftProfile.
    
    :material-location-enter: **Parameter** `body`
    :    JSON string representing the Minecraft player profile.
    
    :material-keyboard-return: **Return**
    :    The MinecraftProfile parsed from the JSON.
    

### GetUUID<a name="GetUUID"></a>
!!! function "[[nodiscard]] std::string GetUUID() const noexcept(false)"

    
    
    Get the UUID of the Minecraft player.
    
    :material-keyboard-return: **Return**
    :    The UUID of the player.
    
    :material-alert-circle-outline: **Throw**
    :    std::runtime_error if the 'id' field is missing in the JSON.
    

