title: AuthenticationResponse
description: Represents the response from an authentication request.
generator: doxide
---


# AuthenticationResponse

**struct AuthenticationResponse**



Represents the response from an authentication request.

AuthenticationResponse stores information received as a response
to an authentication request, including the token type, scope,
expiration time, access token, and refresh token.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_TokenType](#m_TokenType) |  Type of the access token. |
| [m_Scope](#m_Scope) |  Scope of the access token. |
| [expiresIn](#expiresIn) |  Expiration time of the access token in seconds. |
| [m_AccessToken](#m_AccessToken) |  Access token for authentication. |
| [m_RefreshToken](#m_RefreshToken) |  Refresh token for obtaining a new access token. |

## Functions

| Name | Description |
| ---- | ----------- |
| [FromJson](#FromJson) | Parse a JSON string to create an AuthenticationResponse. |

## Variable Details

### expiresIn<a name="expiresIn"></a>

!!! variable "int expiresIn"

     Expiration time of the access token in seconds.

### m_AccessToken<a name="m_AccessToken"></a>

!!! variable "std::string m_AccessToken"

     Access token for authentication.

### m_RefreshToken<a name="m_RefreshToken"></a>

!!! variable "std::string m_RefreshToken"

     Refresh token for obtaining a new access token.

### m_Scope<a name="m_Scope"></a>

!!! variable "std::string m_Scope"

     Scope of the access token.

### m_TokenType<a name="m_TokenType"></a>

!!! variable "std::string m_TokenType"

     Type of the access token.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static AuthenticationResponse FromJson(const std::string&amp; body)"

    
    
    Parse a JSON string to create an AuthenticationResponse.
    
    :material-location-enter: **Parameter** `body`
    :    JSON string representing the authentication response.
    
    :material-keyboard-return: **Return**
    :    The AuthenticationResponse parsed from the JSON.
    

