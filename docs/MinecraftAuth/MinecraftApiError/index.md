title: MinecraftApiError
description: Represents an error response from a Minecraft API request.
generator: doxide
---


# MinecraftApiError

**struct MinecraftApiError**



Represents an error response from a Minecraft API request.

MinecraftApiError stores information received as an error response
from a Minecraft API request, including the request path, error type,
specific error, error message, and developer-specific message.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_Path](#m_Path) |  The path of the API request that resulted in an error. |
| [m_ErrorType](#m_ErrorType) |  The type or category of the error. |
| [m_Error](#m_Error) |  Specific error code or identifier. |
| [m_ErrorMessage](#m_ErrorMessage) |  Descriptive error message. |
| [m_DeveloperMessage](#m_DeveloperMessage) |  Developer-specific message providing additional context. |

## Functions

| Name | Description |
| ---- | ----------- |
| [FromJson](#FromJson) | Parse a JSON string to create a MinecraftApiError. |

## Variable Details

### m_DeveloperMessage<a name="m_DeveloperMessage"></a>

!!! variable "std::string m_DeveloperMessage"

     Developer-specific message providing additional context.

### m_Error<a name="m_Error"></a>

!!! variable "std::string m_Error"

     Specific error code or identifier.

### m_ErrorMessage<a name="m_ErrorMessage"></a>

!!! variable "std::string m_ErrorMessage"

     Descriptive error message.

### m_ErrorType<a name="m_ErrorType"></a>

!!! variable "std::string m_ErrorType"

     The type or category of the error.

### m_Path<a name="m_Path"></a>

!!! variable "std::string m_Path"

     The path of the API request that resulted in an error.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static MinecraftApiError FromJson(const std::string&amp; jsonStr)"

    
    
    Parse a JSON string to create a MinecraftApiError.
    
    :material-location-enter: **Parameter** `jsonStr`
    :    JSON string representing the Minecraft API error response.
    
    :material-keyboard-return: **Return**
    :    The MinecraftApiError parsed from the JSON.
    

