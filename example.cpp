//
// Created by synse on 12/11/23.
//

#include <iostream>

#include "MinecraftAuth/MicrosoftOAuth.h"
#include "MinecraftAuth/Http/cpp-httplib/HttpLibHttpEngine.h"

int main() {
    const MinecraftAuth::HttpLibHttpEngine engine;
    const MinecraftAuth::AuthenticationResponse msAuth = MinecraftAuth::MicrosoftOAuth::DeviceAuth(engine);
    const MinecraftAuth::Account account = MinecraftAuth::MicrosoftOAuth::LoginToAccount(engine, msAuth);
    std::cout << "Hello, " << account.m_Username << "!" << std::endl;
    std::cout << "Your uuid is " << account.m_UUID << std::endl;
    return 0;
}
