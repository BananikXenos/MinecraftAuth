cmake_minimum_required(VERSION 3.27)
project(MinecraftAuth)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(httplib SYSTEM
        GIT_REPOSITORY https://github.com/yhirose/cpp-httplib
        GIT_TAG a609330e4c6374f741d3b369269f7848255e1954 # v0.14.1
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(httplib)

add_library(MinecraftAuth
        MinecraftAuth/Http/HttpResponse.h
        MinecraftAuth/Http/HttpEngine.cpp
        MinecraftAuth/Http/HttpEngine.h
        MinecraftAuth/Utils/StringUtils.h
        MinecraftAuth/Http/cpp-httplib/HttpLibHttpEngine.cpp
        MinecraftAuth/Http/cpp-httplib/HttpLibHttpEngine.h
        MinecraftAuth/Data/MinecraftProfile.h
        MinecraftAuth/Data/MinecraftProfile.cpp
        MinecraftAuth/Data/Account.cpp
        MinecraftAuth/Data/Account.h
        MinecraftAuth/Data/Responses/AuthenticationResponse.h
        MinecraftAuth/Data/Responses/MinecraftAuthResponse.h
        MinecraftAuth/MicrosoftOAuth.cpp
        MinecraftAuth/MicrosoftOAuth.h
        MinecraftAuth/Data/Responses/DeviceAuthorizationResponse.h
        MinecraftAuth/Data/Responses/XBLAuthenticationResponse.h
        MinecraftAuth/Data/Responses/XSTSAuthenticationResponse.h
        MinecraftAuth/Data/Responses/MicrosoftApiError.h
        MinecraftAuth/Data/Responses/XboxApiError.h
        MinecraftAuth/Data/Responses/MinecraftApiError.h
        MinecraftAuth/Http/HttpResponse.cpp
        # example.cpp
)

target_link_libraries(MinecraftAuth PUBLIC nlohmann_json::nlohmann_json OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB httplib)
