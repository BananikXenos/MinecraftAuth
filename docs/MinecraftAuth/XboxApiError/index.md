title: XboxApiError
description: Represents an error response from Xbox APIs.
generator: doxide
---


# XboxApiError

**struct XboxApiError**



Represents an error response from Xbox APIs.

XboxApiError stores information about errors returned from Xbox APIs,
including identity, error code (XErr), error message, and redirection URL.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_Identity](#m_Identity) |  The identity associated with the error. |
| [m_XErr](#m_XErr) |  The error code (XErr) indicating the type of error. |
| [m_Message](#m_Message) |  The error message describing the issue. |
| [m_Redirect](#m_Redirect) |  The URL to redirect to in case of an error. |

## Functions

| Name | Description |
| ---- | ----------- |
| [FromJson](#FromJson) | Parse a JSON string to create an XboxApiError instance. |

## Variable Details

### m_Identity<a name="m_Identity"></a>

!!! variable "int m_Identity"

     The identity associated with the error.

### m_Message<a name="m_Message"></a>

!!! variable "std::string m_Message"

     The error message describing the issue.

### m_Redirect<a name="m_Redirect"></a>

!!! variable "std::string m_Redirect"

     The URL to redirect to in case of an error.

### m_XErr<a name="m_XErr"></a>

!!! variable "long m_XErr"

     The error code (XErr) indicating the type of error.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static XboxApiError FromJson(const std::string&amp; body)"

    
    
    Parse a JSON string to create an XboxApiError instance.
    
    :material-location-enter: **Parameter** `body`
    :    JSON string representing the Xbox API error response.
    
    :material-keyboard-return: **Return**
    :    The XboxApiError instance parsed from the JSON.
    

