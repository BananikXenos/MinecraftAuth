title: MSTokens
description: Represents Microsoft Account tokens.
generator: doxide
---


# MSTokens

**class MSTokens**



Represents Microsoft Account tokens.

MSTokens stores Microsoft Account tokens including access token,
refresh token, and expiration timestamp.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_AccessToken](#m_AccessToken) |  Microsoft Access Token. |
| [m_RefreshToken](#m_RefreshToken) |  Microsoft Refresh Token. |
| [m_ExpiresAt](#m_ExpiresAt) |  Expiration timestamp. |

## Functions

| Name | Description |
| ---- | ----------- |
| [MSTokens](#MSTokens) | Default constructor for MSTokens.  |
| [MSTokens](#MSTokens) | Constructor for MSTokens using AuthenticationResponse. |

## Variable Details

### m_AccessToken<a name="m_AccessToken"></a>

!!! variable "std::string m_AccessToken"

     Microsoft Access Token.

### m_ExpiresAt<a name="m_ExpiresAt"></a>

!!! variable "long m_ExpiresAt"

     Expiration timestamp.

### m_RefreshToken<a name="m_RefreshToken"></a>

!!! variable "std::string m_RefreshToken"

     Microsoft Refresh Token.

## Function Details

### MSTokens<a name="MSTokens"></a>
!!! function "MSTokens() = default"

    
    
    Default constructor for MSTokens.
             
    
    

!!! function "explicit MSTokens(const AuthenticationResponse&amp; auth)"

    
    
    Constructor for MSTokens using AuthenticationResponse.
    
    :material-location-enter: **Parameter** `auth`
    :    AuthenticationResponse containing Microsoft tokens.
        

