# MinecraftAuth

MinecraftAuth is a C++ library for handling Minecraft authentication. It serves as a rewrite of [DevLogin](https://github.com/covers1624/DevLogin) and utilizes the following libraries:
- [cpp-httplib](https://github.com/yhirose/cpp-httplib)
- [OpenSSL](https://www.openssl.org/)
- [nlohmann/json](https://github.com/nlohmann/json)

## Features

- Microsoft's authentication support
- Xbox Live authentication support
- Minecraft's authentication support
- HTTP engine using cpp-httplib
- Utility functions for string manipulation

## Installation

To use MinecraftAuth in your C++ project, include the necessary header files and link against the libraries. Ensure that cpp-httplib, OpenSSL, and nlohmann/json are properly installed.

## Usage

Check out the [example code](#example) below to see how MinecraftAuth can be used to handle Minecraft authentication.

## Example

### Authentication Flow

The following example demonstrates the authentication flow using MinecraftAuth:

```cpp
#include <iostream>

#include "MinecraftAuth/MicrosoftOAuth.h"
#include "MinecraftAuth/Http/cpp-httplib/HttpLibHttpEngine.h"

int main() {
    const MinecraftAuth::HttpLibHttpEngine engine;
    const MinecraftAuth::AuthenticationResponse msAuth = MinecraftAuth::MicrosoftOAuth::DeviceAuth(engine);
    const MinecraftAuth::Account account = MinecraftAuth::MicrosoftOAuth::LoginToAccount(engine, msAuth);
    std::cout << "Hello, " << account.m_Username << "!" << std::endl;
    return 0;
}
```

The authentication link and code will be printed to the console. Open the link in a browser and enter the code to authenticate.

## Support

If you find MinecraftAuth useful, you can support the project by:

- [Making a donation via PayPal](https://paypal.me/scgxenos)
- [Buying me a coffee](https://www.buymeacoffee.com/synse)

Your support is greatly appreciated and helps to keep the project active and maintained.

## License

MinecraftAuth is released under the [MIT License](https://choosealicense.com/licenses/mit/).