title: MCTokens
description: Represents Minecraft Account tokens.
generator: doxide
---


# MCTokens

**class MCTokens**



Represents Minecraft Account tokens.

MCTokens stores Minecraft Account tokens including access token
and expiration timestamp.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_AccessToken](#m_AccessToken) |  Minecraft Access Token. |
| [m_ExpiresAt](#m_ExpiresAt) |  Expiration timestamp. |

## Functions

| Name | Description |
| ---- | ----------- |
| [MCTokens](#MCTokens) | Default constructor for MCTokens.  |
| [MCTokens](#MCTokens) | Constructor for MCTokens using MinecraftAuthResponse. |

## Variable Details

### m_AccessToken<a name="m_AccessToken"></a>

!!! variable "std::string m_AccessToken"

     Minecraft Access Token.

### m_ExpiresAt<a name="m_ExpiresAt"></a>

!!! variable "long m_ExpiresAt"

     Expiration timestamp.

## Function Details

### MCTokens<a name="MCTokens"></a>
!!! function "MCTokens() = default"

    
    
    Default constructor for MCTokens.
             
    
    

!!! function "explicit MCTokens(const MinecraftAuthResponse&amp; auth)"

    
    
    Constructor for MCTokens using MinecraftAuthResponse.
    
    :material-location-enter: **Parameter** `auth`
    :    MinecraftAuthResponse containing Minecraft tokens.
        

