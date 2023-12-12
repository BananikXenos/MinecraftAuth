title: Account
description: Represents a Minecraft account.
generator: doxide
---


# Account

**class Account**



Represents a Minecraft account.

The Account class stores information about a Minecraft account,
including the username, UUID, and tokens for both Microsoft and Minecraft.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_Username](#m_Username) |  Minecraft account username. |
| [m_UUID](#m_UUID) |  Minecraft account UUID. |
| [m_MSTokens](#m_MSTokens) |  Microsoft Account tokens. |
| [m_MCTokens](#m_MCTokens) |  Minecraft Account tokens. |

## Functions

| Name | Description |
| ---- | ----------- |
| [Account](#Account) | Constructor for Account using MinecraftProfile, AuthenticationResponse, and MinecraftAuthResponse. |

## Variable Details

### m_MCTokens<a name="m_MCTokens"></a>

!!! variable "MCTokens m_MCTokens"

     Minecraft Account tokens.

### m_MSTokens<a name="m_MSTokens"></a>

!!! variable "MSTokens m_MSTokens"

     Microsoft Account tokens.

### m_UUID<a name="m_UUID"></a>

!!! variable "std::string m_UUID"

     Minecraft account UUID.

### m_Username<a name="m_Username"></a>

!!! variable "std::string m_Username"

     Minecraft account username.

## Function Details

### Account<a name="Account"></a>
!!! function "Account(const MinecraftProfile&amp; mcProfile, const AuthenticationResponse&amp; msAuth, const MinecraftAuthResponse&amp; mcAuth)"

    
    
    Constructor for Account using MinecraftProfile, AuthenticationResponse, and MinecraftAuthResponse.
    
    :material-location-enter: **Parameter** `mcProfile`
    :    MinecraftProfile containing Minecraft account information.
    
    :material-location-enter: **Parameter** `msAuth`
    :    AuthenticationResponse containing Microsoft Account tokens.
    
    :material-location-enter: **Parameter** `mcAuth`
    :    MinecraftAuthResponse containing Minecraft Account tokens.
        

