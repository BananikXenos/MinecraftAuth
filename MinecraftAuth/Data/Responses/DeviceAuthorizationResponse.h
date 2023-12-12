//
// Created by synse on 12/11/23.
//

#ifndef DEVICEAUTHORIZATIONRESPONSE_H
#define DEVICEAUTHORIZATIONRESPONSE_H
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace MinecraftAuth {
    /**
     * @brief Represents the response from a device authorization request.
     *
     * DeviceAuthorizationResponse stores information received as a response
     * to a device authorization request, including the user code, device code,
     * verification URL, expiration time, interval, and an optional message.
     */
    struct DeviceAuthorizationResponse {
        std::string m_UserCode; ///< User code for device authorization.
        std::string m_DeviceCode; ///< Device code for device authorization.
        std::string m_VerificationUrl; ///< Verification URL for the user to authorize the device.
        int m_ExpiresIn; ///< Expiration time of the device authorization in seconds.
        int m_Interval; ///< Interval at which the device should check for authorization.
        std::string m_Message; ///< Optional message associated with the authorization.

        /**
         * @brief Parse a JSON string to create a DeviceAuthorizationResponse.
         *
         * @param body JSON string representing the device authorization response.
         * @return The DeviceAuthorizationResponse parsed from the JSON.
         */
        static DeviceAuthorizationResponse FromJson(const std::string& body) {
            json j = json::parse(body);
            const std::string& userCode = j["user_code"];
            const std::string& deviceCode = j["device_code"];
            const std::string& verificationUrl = j["verification_uri"];
            const int expiresIn = j["expires_in"];
            const int interval = j["interval"];
            const std::string& message = j["message"];
            return {userCode, deviceCode, verificationUrl, expiresIn, interval, message};
        }
    };
} // MinecraftAuth

#endif //DEVICEAUTHORIZATIONRESPONSE_H
