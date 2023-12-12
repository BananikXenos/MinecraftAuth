title: HttpEngine
description: Interface for HTTP request handling.
generator: doxide
---


# HttpEngine

**class HttpEngine**



Interface for HTTP request handling.

The HttpEngine class defines an interface for handling HTTP requests, including methods
for sending GET, POST (JSON and Form), and making generic requests. Implementations of
this interface provide the actual HTTP communication functionality.


## Variables

| Name | Description |
| ---- | ----------- |
| [FORM_URL_ENCODED](#FORM_URL_ENCODED) | Content types for HTTP requests.  |

## Functions

| Name | Description |
| ---- | ----------- |
| [~HttpEngine](#_u007eHttpEngine) | Virtual destructor for the HttpEngine class.  |
| [GetJson](#GetJson) | Sends a GET request with optional headers and retrieves JSON response. |
| [PostJson](#PostJson) | Sends a POST request with JSON body and optional headers. |
| [PostForm](#PostForm) | Sends a POST request with form-encoded body and optional headers. |
| [MakeRequest](#MakeRequest) | Makes a generic HTTP request with specified method, URL, body, and headers. |
| [RequiresRequestBody](#RequiresRequestBody) | Checks if a request method requires a request body. |

## Variable Details

### FORM_URL_ENCODED<a name="FORM_URL_ENCODED"></a>

!!! variable "static inline const std::string FORM_URL_ENCODED"

    
    
    Content types for HTTP requests.
             
    
    

## Function Details

### GetJson<a name="GetJson"></a>
!!! function "[[nodiscard]] HttpResponse GetJson(const std::string&amp; url, const std::unordered_map&lt;std::string, std::string&gt;&amp; headers = {}) const"

    
    
    Sends a GET request with optional headers and retrieves JSON response.
    
    :material-location-enter: **Parameter** `url`
    :    The URL for the GET request.
    
    :material-location-enter: **Parameter** `headers`
    :    Optional headers to include in the request.
    
    :material-keyboard-return: **Return**
    :    The HTTP response containing the JSON data.
    

### MakeRequest<a name="MakeRequest"></a>
!!! function "[[nodiscard]] virtual HttpResponse MakeRequest(const std::string&amp; method, const std::string&amp; url, const std::string&amp; body, const std::unordered_map&lt;std::string, std::string&gt;&amp; headers) const = 0"

    
    
    Makes a generic HTTP request with specified method, URL, body, and headers.
    
    This method needs to be implemented by the concrete HTTP engine.
    
    :material-location-enter: **Parameter** `method`
    :    The HTTP method (e.g., GET, POST, etc.).
    
    :material-location-enter: **Parameter** `url`
    :    The URL for the request.
    
    :material-location-enter: **Parameter** `body`
    :    The body of the request.
    
    :material-location-enter: **Parameter** `headers`
    :    Optional headers to include in the request.
    
    :material-keyboard-return: **Return**
    :    The HTTP response for the generic request.
    

### PostForm<a name="PostForm"></a>
!!! function "[[nodiscard]] HttpResponse PostForm(const std::string&amp; url, const std::unordered_map&lt;std::string, std::string&gt;&amp; body = {}, const std::unordered_map&lt;std::string, std::string&gt;&amp; headers = {}) const"

    
    
    Sends a POST request with form-encoded body and optional headers.
    
    :material-location-enter: **Parameter** `url`
    :    The URL for the POST request.
    
    :material-location-enter: **Parameter** `body`
    :    The form-encoded body to include in the request.
    
    :material-location-enter: **Parameter** `headers`
    :    Optional headers to include in the request.
    
    :material-keyboard-return: **Return**
    :    The HTTP response for the POST request.
    

### PostJson<a name="PostJson"></a>
!!! function "[[nodiscard]] HttpResponse PostJson(const std::string&amp; url, const std::string&amp; body = {}, const std::unordered_map&lt;std::string, std::string&gt;&amp; headers = {}) const"

    
    
    Sends a POST request with JSON body and optional headers.
    
    :material-location-enter: **Parameter** `url`
    :    The URL for the POST request.
    
    :material-location-enter: **Parameter** `body`
    :    The JSON body to include in the request.
    
    :material-location-enter: **Parameter** `headers`
    :    Optional headers to include in the request.
    
    :material-keyboard-return: **Return**
    :    The HTTP response for the POST request.
    

### RequiresRequestBody<a name="RequiresRequestBody"></a>
!!! function "static bool RequiresRequestBody(const std::string&amp; method)"

    
    
    Checks if a request method requires a request body.
    
    :material-location-enter: **Parameter** `method`
    :    The HTTP method to check.
    
    :material-keyboard-return: **Return**
    :    True if the method requires a request body, false otherwise.
    

### ~HttpEngine<a name="_u007eHttpEngine"></a>
!!! function "virtual ~HttpEngine() = default"

    
    
    Virtual destructor for the HttpEngine class.
             
    
    

