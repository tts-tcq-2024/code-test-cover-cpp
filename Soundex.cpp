#include "Soundex.h"
#include <cctype>
#include <unordered_map>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    auto it = soundexMap.find(toupper(c));
    return it == soundexMap.end() ? '0' : it->second;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex;
    soundex.reserve(4);

    char firstChar = toupper(name[0]);
    soundex += firstChar;

    char prevCode = getSoundexCode(firstChar);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        } else if (code == '0' && (name[i] == 'H' || name[i] == 'W') && i + 1 < name.length()) {
            char nextCode = getSoundexCode(name[i + 1]);
            if (nextCode == prevCode) continue;
        }
    }

    soundex.append(4 - soundex.length(), '0');
    return soundex;
}
