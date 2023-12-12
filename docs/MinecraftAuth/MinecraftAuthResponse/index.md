title: MinecraftAuthResponse
description: Represents the response from authenticating with Minecraft services.
generator: doxide
---


# MinecraftAuthResponse

**struct MinecraftAuthResponse**



Represents the response from authenticating with Minecraft services.

MinecraftAuthResponse stores information obtained when authenticating
with Minecraft services, including the authenticated username, roles,
access token, token type, and expiration duration.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_Username](#m_Username) |  The authenticated username. |
| [m_Roles](#m_Roles) |  List of roles associated with the user. |
| [m_AccessToken](#m_AccessToken) |  The access token obtained during authentication. |
| [m_TokenType](#m_TokenType) |  The type of token (e. |
| [m_ExpiresIn](#m_ExpiresIn) |  Duration (in seconds) until the access token expires. |

## Functions

| Name | Description |
| ---- | ----------- |
| [FromJson](#FromJson) | Parse a JSON string to create a MinecraftAuthResponse. |

## Variable Details

### m_AccessToken<a name="m_AccessToken"></a>

!!! variable "std::string m_AccessToken"

     The access token obtained during authentication.

### m_ExpiresIn<a name="m_ExpiresIn"></a>

!!! variable "int m_ExpiresIn"

     Duration (in seconds) until the access token expires.

### m_Roles<a name="m_Roles"></a>

!!! variable "std::vector&lt;std::string&gt; m_Roles"

     List of roles associated with the user.

### m_TokenType<a name="m_TokenType"></a>

!!! variable "std::string m_TokenType"

     The type of token (e.g., "Bearer").

### m_Username<a name="m_Username"></a>

!!! variable "std::string m_Username"

     The authenticated username.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static MinecraftAuthResponse FromJson(const std::string&amp; body)"

    
    
    Parse a JSON string to create a MinecraftAuthResponse.
    
    :material-location-enter: **Parameter** `body`
    :    JSON string representing the Minecraft authentication response.
    
    :material-keyboard-return: **Return**
    :    The MinecraftAuthResponse parsed from the JSON.
    

