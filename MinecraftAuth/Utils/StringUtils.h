//
// Created by synse on 12/11/23.
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

namespace MinecraftAuth {
    /**
     * @brief Utility class for string-related operations.
     *
     * The StringUtils class provides various string manipulation and comparison functions,
     * including case-insensitive character and string comparison.
     */
    class StringUtils {
    public:
        /**
         * @brief Case-insensitive character comparison.
         *
         * @param a The first character.
         * @param b The second character.
         * @return true if characters are equal ignoring case, false otherwise.
         */
        static bool ichar_equals(char a, char b) {
            return std::tolower(static_cast<unsigned char>(a)) ==
                   std::tolower(static_cast<unsigned char>(b));
        }

        /**
         * @brief Case-insensitive string comparison.
         *
         * @param a The first string.
         * @param b The second string.
         * @return true if strings are equal ignoring case, false otherwise.
         */
        static bool iequals(const std::string& a, const std::string& b) {
            return a.size() == b.size() &&
                   std::equal(a.begin(), a.end(), b.begin(), ichar_equals);
        }
    };
} // MinecraftAuth

#endif //STRINGUTILS_H
