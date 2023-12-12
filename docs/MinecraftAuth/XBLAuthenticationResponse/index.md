title: XBLAuthenticationResponse
description: Represents the response from authenticating with Xbox Live services.
generator: doxide
---


# XBLAuthenticationResponse

**struct XBLAuthenticationResponse**



Represents the response from authenticating with Xbox Live services.

XBLAuthenticationResponse stores information obtained when authenticating
with Xbox Live services, including issue instant, expiration time, token,
and display claims.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_IssueInstant](#m_IssueInstant) |  The timestamp when the token was issued. |
| [m_NotAfter](#m_NotAfter) |  The timestamp indicating when the token expires. |
| [m_Token](#m_Token) |  The authentication token from Xbox Live. |
| [m_DisplayClaims](#m_DisplayClaims) |  Display claims associated with the user. |

## Functions

| Name | Description |
| ---- | ----------- |
| [GetXUID](#GetXUID) | Get the XUID (Xbox User ID) from the display claims. |
| [FromJson](#FromJson) | Parse a JSON string to create an XBLAuthenticationResponse. |

## Variable Details

### m_DisplayClaims<a name="m_DisplayClaims"></a>

!!! variable "json m_DisplayClaims"

     Display claims associated with the user.

### m_IssueInstant<a name="m_IssueInstant"></a>

!!! variable "std::string m_IssueInstant"

     The timestamp when the token was issued.

### m_NotAfter<a name="m_NotAfter"></a>

!!! variable "std::string m_NotAfter"

     The timestamp indicating when the token expires.

### m_Token<a name="m_Token"></a>

!!! variable "std::string m_Token"

     The authentication token from Xbox Live.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static XBLAuthenticationResponse FromJson(const std::string&amp; body)"

    
    
    Parse a JSON string to create an XBLAuthenticationResponse.
    
    :material-location-enter: **Parameter** `body`
    :    JSON string representing the Xbox Live authentication response.
    
    :material-keyboard-return: **Return**
    :    The XBLAuthenticationResponse parsed from the JSON.
    

### GetXUID<a name="GetXUID"></a>
!!! function "[[nodiscard]] std::string GetXUID() const"

    
    
    Get the XUID (Xbox User ID) from the display claims.
    
    :material-keyboard-return: **Return**
    :    The Xbox User ID (XUID) extracted from the display claims.
    

