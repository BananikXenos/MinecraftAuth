title: HttpResponse
description: Represents an HTTP response.
generator: doxide
---


# HttpResponse

**class HttpResponse**



Represents an HTTP response.

The HttpResponse class encapsulates the details of an HTTP response, including
the status code, message, and the response body. It provides a convenient method
for deserializing the response body into a specified type using the FromJson method.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_Code](#m_Code) |  The HTTP status code. |
| [m_Message](#m_Message) |  The status message associated with the code. |
| [m_Body](#m_Body) |  The response body as a string. |

## Functions

| Name | Description |
| ---- | ----------- |
| [HttpResponse](#HttpResponse) | Constructor for HttpResponse. |
| [FromJson](#FromJson) | Deserializes the response body into the specified type. |

## Variable Details

### m_Body<a name="m_Body"></a>

!!! variable "const std::string m_Body"

     The response body as a string.

### m_Code<a name="m_Code"></a>

!!! variable "const int m_Code"

     The HTTP status code.

### m_Message<a name="m_Message"></a>

!!! variable "const std::string m_Message"

     The status message associated with the code.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "template&lt;typename T&gt; T FromJson()"

    
    
    Deserializes the response body into the specified type.
    
    This method uses the FromJson method of the target type to convert the
    response body from JSON to the specified type.
    
    :material-code-tags: **Template parameter** `T`
    :    The type to deserialize the response body into.
    
    :material-keyboard-return: **Return**
    :    An instance of type T populated with data from the response body.
    

### HttpResponse<a name="HttpResponse"></a>
!!! function "HttpResponse(int code, std::string message, std::string body)"

    
    
    Constructor for HttpResponse.
    
    :material-location-enter: **Parameter** `code`
    :    The HTTP status code.
    
    :material-location-enter: **Parameter** `message`
    :    The status message associated with the code.
    
    :material-location-enter: **Parameter** `body`
    :    The response body as a string.
        

