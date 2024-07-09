#include "Soundex.h"
#include <cctype>

// Helper function to get Soundex code for a character
char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

// Main function to generate Soundex code for a name
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex;
    soundex.reserve(4); // Reserve space for 4 characters

    soundex += toupper(name[0]); // Add the first character

    char prevCode = getSoundexCode(name[0]); // Get Soundex code for the first character

    // Iterate through the remaining characters in the name
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]); // Get Soundex code for the current character
        if (code != '0' && code != prevCode) { // Check if code is valid and different from previous
            soundex += code; // Add valid code to Soundex string
            prevCode = code; // Update previous code
        }
    }

    soundex.append(4 - soundex.length(), '0'); // Pad with zeros if necessary to ensure length 4

    return soundex; // Return the generated Soundex code
}
