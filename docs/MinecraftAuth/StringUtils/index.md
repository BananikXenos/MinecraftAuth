title: StringUtils
description: Utility class for string-related operations.
generator: doxide
---


# StringUtils

**class StringUtils**



Utility class for string-related operations.

The StringUtils class provides various string manipulation and comparison functions,
including case-insensitive character and string comparison.


## Functions

| Name | Description |
| ---- | ----------- |
| [ichar_equals](#ichar_equals) | Case-insensitive character comparison. |
| [iequals](#iequals) | Case-insensitive string comparison. |

## Function Details

### ichar_equals<a name="ichar_equals"></a>
!!! function "static bool ichar_equals(char a, char b)"

    
    
    Case-insensitive character comparison.
    
    :material-location-enter: **Parameter** `a`
    :    The first character.
    
    :material-location-enter: **Parameter** `b`
    :    The second character.
    
    :material-keyboard-return: **Return**
    :    true if characters are equal ignoring case, false otherwise.
    

### iequals<a name="iequals"></a>
!!! function "static bool iequals(const std::string&amp; a, const std::string&amp; b)"

    
    
    Case-insensitive string comparison.
    
    :material-location-enter: **Parameter** `a`
    :    The first string.
    
    :material-location-enter: **Parameter** `b`
    :    The second string.
    
    :material-keyboard-return: **Return**
    :    true if strings are equal ignoring case, false otherwise.
    

