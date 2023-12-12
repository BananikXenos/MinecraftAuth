title: HttpLibHttpEngine
description: HTTP engine implementation using the httplib library.
generator: doxide
---


# HttpLibHttpEngine

**class HttpLibHttpEngine final : public HttpEngine**



HTTP engine implementation using the httplib library.

The HttpLibHttpEngine class extends the HttpEngine interface and provides
an implementation using the httplib library for making HTTP requests.


## Functions

| Name | Description |
| ---- | ----------- |
| [MakeRequest](#MakeRequest) | Makes an HTTP request using the httplib library. |

## Function Details

### MakeRequest<a name="MakeRequest"></a>
!!! function "[[nodiscard]] HttpResponse MakeRequest(const std::string&amp; method, const std::string&amp; url, const std::string&amp; body, const std::unordered_map&lt;std::string, std::string&gt;&amp; headers) const override"

    
    
    Makes an HTTP request using the httplib library.
    
    :material-location-enter: **Parameter** `method`
    :    The HTTP method (e.g., GET, POST).
    
    :material-location-enter: **Parameter** `url`
    :    The URL for the HTTP request.
    
    :material-location-enter: **Parameter** `body`
    :    The request body for methods that support it.
    
    :material-location-enter: **Parameter** `headers`
    :    Additional headers to include in the request.
    
    :material-keyboard-return: **Return**
    :    The HttpResponse object representing the HTTP response.
    
    @throws std::invalid_argument if the URL is in an invalid format.
    
    @throws std::invalid_argument if the HTTP method is invalid.
    
    @throws std::runtime_error if the HTTP request fails.
    

