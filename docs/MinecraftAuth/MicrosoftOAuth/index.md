title: MicrosoftOAuth
description: MicrosoftOAuth class for handling Microsoft OAuth flows.
generator: doxide
---


# MicrosoftOAuth

**class MicrosoftOAuth**



MicrosoftOAuth class for handling Microsoft OAuth flows.

This class provides functionalities for Microsoft OAuth, including device
authentication, token retrieval, XBL authentication, XSTS authentication,
and Minecraft authentication.


## Functions

| Name | Description |
| ---- | ----------- |
| [DeviceAuth](#DeviceAuth) | Initiates device authentication flow. |
| [StartDeviceAuth](#StartDeviceAuth) | Starts the device authentication process. |
| [CheckDeviceAuth](#CheckDeviceAuth) | Checks the status of device authentication. |
| [RefreshMicrosoftAuth](#RefreshMicrosoftAuth) | Refreshes the Microsoft authentication using the provided refresh token. |
| [LoginToAccount](#LoginToAccount) | Logs in to a Minecraft account using Microsoft authentication details. |
| [ValidateAccount](#ValidateAccount) | Validates the Minecraft account and refreshes the token if necessary. |
| [RefreshMinecraftToken](#RefreshMinecraftToken) | Refreshes the Minecraft access token for the given account. |
| [RefreshMicrosoftToken](#RefreshMicrosoftToken) | Refreshes the Microsoft access token for the given account. |
| [AuthenticateWithXBL](#AuthenticateWithXBL) | Authenticates with Xbox Live (XBL) using the provided authentication token. |
| [AuthenticateWithXSTS](#AuthenticateWithXSTS) | Authenticates with Xbox Secure Token Service (XSTS) using XBL authentication details. |
| [AuthenticateWithMinecraft](#AuthenticateWithMinecraft) | Authenticates with Minecraft services using XBL and XSTS authentication details. |
| [GetMinecraftProfile](#GetMinecraftProfile) | Retrieves the Minecraft profile using the provided Minecraft authentication details. |

## Function Details

### AuthenticateWithMinecraft<a name="AuthenticateWithMinecraft"></a>
!!! function "static MinecraftAuthResponse AuthenticateWithMinecraft(const HttpEngine&amp; engine, const XBLAuthenticationResponse&amp; xblAuth, const XSTSAuthenticationResponse&amp; xstsAuth)"

    
    
    Authenticates with Minecraft services using XBL and XSTS authentication details.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `xblAuth`
    :    XBLAuthenticationResponse containing XBL authentication details.
    
    :material-location-enter: **Parameter** `xstsAuth`
    :    XSTSAuthenticationResponse containing XSTS authentication details.
    
    :material-keyboard-return: **Return**
    :    MinecraftAuthResponse containing Minecraft authentication details.
    

### AuthenticateWithXBL<a name="AuthenticateWithXBL"></a>
!!! function "static XBLAuthenticationResponse AuthenticateWithXBL(const HttpEngine&amp; engine, const std::string&amp; authToken)"

    
    
    Authenticates with Xbox Live (XBL) using the provided authentication token.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `authToken`
    :    Authentication token used for XBL authentication.
    
    :material-keyboard-return: **Return**
    :    XBLAuthenticationResponse containing XBL authentication details.
    

### AuthenticateWithXSTS<a name="AuthenticateWithXSTS"></a>
!!! function "static XSTSAuthenticationResponse AuthenticateWithXSTS(const HttpEngine&amp; engine, const XBLAuthenticationResponse&amp; auth)"

    
    
    Authenticates with Xbox Secure Token Service (XSTS) using XBL authentication details.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `auth`
    :    XBLAuthenticationResponse containing XBL authentication details.
    
    :material-keyboard-return: **Return**
    :    XSTSAuthenticationResponse containing XSTS authentication details.
    

### CheckDeviceAuth<a name="CheckDeviceAuth"></a>
!!! function "static AuthenticationResponse CheckDeviceAuth(const HttpEngine&amp; engine, const DeviceAuthorizationResponse&amp; deviceAuth)"

    
    
    Checks the status of device authentication.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `deviceAuth`
    :    DeviceAuthorizationResponse containing device authorization details.
    
    :material-keyboard-return: **Return**
    :    AuthenticationResponse containing the access token upon successful authentication.
    

### DeviceAuth<a name="DeviceAuth"></a>
!!! function "static AuthenticationResponse DeviceAuth(const HttpEngine&amp; engine)"

    
    
    Initiates device authentication flow.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-keyboard-return: **Return**
    :    AuthenticationResponse containing device authentication details.
    

### GetMinecraftProfile<a name="GetMinecraftProfile"></a>
!!! function "static MinecraftProfile GetMinecraftProfile(const HttpEngine&amp; engine, const MinecraftAuthResponse&amp; minecraftAuth)"

    
    
    Retrieves the Minecraft profile using the provided Minecraft authentication details.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `minecraftAuth`
    :    MinecraftAuthResponse containing Minecraft authentication details.
    
    :material-keyboard-return: **Return**
    :    MinecraftProfile representing the Minecraft profile.
    

### LoginToAccount<a name="LoginToAccount"></a>
!!! function "static Account LoginToAccount(const HttpEngine&amp; engine, const AuthenticationResponse&amp; msAuth)"

    
    
    Logs in to a Minecraft account using Microsoft authentication details.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `msAuth`
    :    AuthenticationResponse containing Microsoft authentication details.
    
    :material-keyboard-return: **Return**
    :    Account representing the Minecraft account.
    

### RefreshMicrosoftAuth<a name="RefreshMicrosoftAuth"></a>
!!! function "static AuthenticationResponse RefreshMicrosoftAuth(const HttpEngine&amp; engine, const MSTokens&amp; tokens)"

    
    
    Refreshes the Microsoft authentication using the provided refresh token.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `tokens`
    :    MSTokens containing the refresh token.
    
    :material-keyboard-return: **Return**
    :    AuthenticationResponse containing updated authentication details.
    

### RefreshMicrosoftToken<a name="RefreshMicrosoftToken"></a>
!!! function "static void RefreshMicrosoftToken(const HttpEngine&amp; engine, Account&amp; account)"

    
    
    Refreshes the Microsoft access token for the given account.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `account`
    :    Account for which the Microsoft token should be refreshed.
        

### RefreshMinecraftToken<a name="RefreshMinecraftToken"></a>
!!! function "static void RefreshMinecraftToken(const HttpEngine&amp; engine, Account&amp; account)"

    
    
    Refreshes the Minecraft access token for the given account.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `account`
    :    Account for which the Minecraft token should be refreshed.
        

### StartDeviceAuth<a name="StartDeviceAuth"></a>
!!! function "static DeviceAuthorizationResponse StartDeviceAuth(const HttpEngine&amp; engine)"

    
    
    Starts the device authentication process.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-keyboard-return: **Return**
    :    DeviceAuthorizationResponse containing device authorization details.
    

### ValidateAccount<a name="ValidateAccount"></a>
!!! function "static void ValidateAccount(const HttpEngine&amp; engine, Account&amp; account)"

    
    
    Validates the Minecraft account and refreshes the token if necessary.
    
    :material-location-enter: **Parameter** `engine`
    :    The HttpEngine used for making HTTP requests.
    
    :material-location-enter: **Parameter** `account`
    :    Account to be validated and updated.
        

