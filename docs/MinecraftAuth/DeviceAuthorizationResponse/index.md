title: DeviceAuthorizationResponse
description: Represents the response from a device authorization request.
generator: doxide
---


# DeviceAuthorizationResponse

**struct DeviceAuthorizationResponse**



Represents the response from a device authorization request.

DeviceAuthorizationResponse stores information received as a response
to a device authorization request, including the user code, device code,
verification URL, expiration time, interval, and an optional message.


## Variables

| Name | Description |
| ---- | ----------- |
| [m_UserCode](#m_UserCode) |  User code for device authorization. |
| [m_DeviceCode](#m_DeviceCode) |  Device code for device authorization. |
| [m_VerificationUrl](#m_VerificationUrl) |  Verification URL for the user to authorize the device. |
| [m_ExpiresIn](#m_ExpiresIn) |  Expiration time of the device authorization in seconds. |
| [m_Interval](#m_Interval) |  Interval at which the device should check for authorization. |
| [m_Message](#m_Message) |  Optional message associated with the authorization. |

## Functions

| Name | Description |
| ---- | ----------- |
| [FromJson](#FromJson) | Parse a JSON string to create a DeviceAuthorizationResponse. |

## Variable Details

### m_DeviceCode<a name="m_DeviceCode"></a>

!!! variable "std::string m_DeviceCode"

     Device code for device authorization.

### m_ExpiresIn<a name="m_ExpiresIn"></a>

!!! variable "int m_ExpiresIn"

     Expiration time of the device authorization in seconds.

### m_Interval<a name="m_Interval"></a>

!!! variable "int m_Interval"

     Interval at which the device should check for authorization.

### m_Message<a name="m_Message"></a>

!!! variable "std::string m_Message"

     Optional message associated with the authorization.

### m_UserCode<a name="m_UserCode"></a>

!!! variable "std::string m_UserCode"

     User code for device authorization.

### m_VerificationUrl<a name="m_VerificationUrl"></a>

!!! variable "std::string m_VerificationUrl"

     Verification URL for the user to authorize the device.

## Function Details

### FromJson<a name="FromJson"></a>
!!! function "static DeviceAuthorizationResponse FromJson(const std::string&amp; body)"

    
    
    Parse a JSON string to create a DeviceAuthorizationResponse.
    
    :material-location-enter: **Parameter** `body`
    :    JSON string representing the device authorization response.
    
    :material-keyboard-return: **Return**
    :    The DeviceAuthorizationResponse parsed from the JSON.
    

