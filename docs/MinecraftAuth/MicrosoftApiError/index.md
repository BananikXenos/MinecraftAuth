title: MicrosoftApiError
description: Represents an error response from a Microsoft API request.
generator: doxide
---


# MicrosoftApiError

**struct MicrosoftApiError**



Represents an error response from a Microsoft API request.

MicrosoftApiError stores information received as an error response
from a Microsoft API request, including error code, description, codes,
timestamp, trace ID, correlation ID, and an optional error URI.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_Error](#m_Error) |  Error code or type. |
| [m_ErrorDescription](#m_ErrorDescription) |  Description of the error. |
| [m_ErrorCodes](#m_ErrorCodes) |  Error codes associated with the error. |
| [m_timestamp](#m_timestamp) |  Timestamp when the error occurred. |
| [m_TraceId](#m_TraceId) |  Unique identifier for tracing the error. |
| [m_CorrelationId](#m_CorrelationId) |  Correlation ID for associating multiple requests. |
| [m_ErrorUri](#m_ErrorUri) |  Optional URI providing more information about the error. |

## Functions

| Name | Description |
| ---- | ----------- |
| [FromJson](#FromJson) | Parse a JSON string to create a MicrosoftApiError. |

## Variable Details

### m_CorrelationId<a name="m_CorrelationId"></a>

!!! variable "std::string m_CorrelationId"

     Correlation ID for associating multiple requests.

### m_Error<a name="m_Error"></a>

!!! variable "std::string m_Error"

     Error code or type.

### m_ErrorCodes<a name="m_ErrorCodes"></a>

!!! variable "std::vector&lt;int&gt; m_ErrorCodes"

     Error codes associated with the error.

### m_ErrorDescription<a name="m_ErrorDescription"></a>

!!! variable "std::string m_ErrorDescription"

     Description of the error.

### m_ErrorUri<a name="m_ErrorUri"></a>

!!! variable "std::string m_ErrorUri"

     Optional URI providing more information about the error.

### m_TraceId<a name="m_TraceId"></a>

!!! variable "std::string m_TraceId"

     Unique identifier for tracing the error.

### m_timestamp<a name="m_timestamp"></a>

!!! variable "std::string m_timestamp"

     Timestamp when the error occurred.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static MicrosoftApiError FromJson(const std::string&amp; body)"

    
    
    Parse a JSON string to create a MicrosoftApiError.
    
    :material-location-enter: **Parameter** `body`
    :    JSON string representing the Microsoft API error response.
    
    :material-keyboard-return: **Return**
    :    The MicrosoftApiError parsed from the JSON.
    

