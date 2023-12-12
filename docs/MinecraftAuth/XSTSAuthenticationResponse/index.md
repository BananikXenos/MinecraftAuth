title: XSTSAuthenticationResponse
description: Represents the response from XSTS (Xbox Secure Token Service) authentication.
generator: doxide
---


# XSTSAuthenticationResponse

**struct XSTSAuthenticationResponse**



Represents the response from XSTS (Xbox Secure Token Service) authentication.

XSTSAuthenticationResponse stores information about the XSTS authentication response,
including issue instant, expiration time, authentication token, and display claims.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_IssueInstant](#m_IssueInstant) |  The timestamp when the token was issued. |
| [m_NotAfter](#m_NotAfter) |  The timestamp indicating when the token expires. |
| [m_Token](#m_Token) |  The XSTS authentication token. |
| [m_DisplayClaims](#m_DisplayClaims) |  Additional claims associated with the authentication. |

## Functions

| Name | Description |
| ---- | ----------- |
| [GetXUID](#GetXUID) | Get the XUID (Xbox User ID) from the display claims. |
| [FromJson](#FromJson) | Parse a JSON string to create an XSTSAuthenticationResponse instance. |

## Variable Details

### m_DisplayClaims<a name="m_DisplayClaims"></a>

!!! variable "json m_DisplayClaims"

     Additional claims associated with the authentication.

### m_IssueInstant<a name="m_IssueInstant"></a>

!!! variable "std::string m_IssueInstant"

     The timestamp when the token was issued.

### m_NotAfter<a name="m_NotAfter"></a>

!!! variable "std::string m_NotAfter"

     The timestamp indicating when the token expires.

### m_Token<a name="m_Token"></a>

!!! variable "std::string m_Token"

     The XSTS authentication token.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static XSTSAuthenticationResponse FromJson(const std::string&amp; jsonStr)"

    
    
    Parse a JSON string to create an XSTSAuthenticationResponse instance.
    
    :material-location-enter: **Parameter** `jsonStr`
    :    JSON string representing the XSTS authentication response.
    
    :material-keyboard-return: **Return**
    :    The XSTSAuthenticationResponse instance parsed from the JSON.
    

### GetXUID<a name="GetXUID"></a>
!!! function "std::string GetXUID()"

    
    
    Get the XUID (Xbox User ID) from the display claims.
    
    :material-keyboard-return: **Return**
    :    The Xbox User ID extracted from the display claims.
    

