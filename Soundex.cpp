#include "Soundex.h"
using namespace std;

list<char> vowel = {'A','E','I','O','U'};
list<char> letterHWY = {'H','W','Y'};

char getSoundexCode(char c) 
{
    std::map<char, char> soundexMap = {
        {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'},
        {'H', '0'}, {'W', '0'}, {'Y', '0'}, {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    auto it = soundexMap.find(toupper(c));
    return (it != soundexMap.end()) ? it->second : '0';
}

bool checkIfLetterIsHWY(const std::string& name, size_t& index)
{
    char letterToFind = name[index - 1];
    bool found = false;
    for (char ch : letterHWY) {
        if (ch == letterToFind) {
            found = true;
            break;
        }
    }
    return found;
}

bool checkIfLetterIsVowel(const std::string& name, size_t& index)
{
    char letterToFind = name[index - 1];
    bool found = false;
    for (char ch : vowel) {
        if (ch == letterToFind) {
            found = true;
            break;
        }
    }
    return found;
}

void handelSoundex(std::string& soundex, const std::string& name, size_t& index, char& code, char& prevCode)
{
    if (!checkIfLetterIsHWY(name, index)) 
    {
        soundex += code;
    }
    else if (checkIfLetterIsVowel(name, index))
    {
        soundex += code;
    }
}
 
void createSoundexCode(std::string& soundex, const std::string& name){
    char prevCode = getSoundexCode(name[0]);
    for (size_t index = 1; index <= name.length() && soundex.length() < 4; ++index) {
        char code = getSoundexCode(toupper(name[index]));
        if(code != prevCode && code != '0')
        {
            handelSoundex(soundex, name, index, code, prevCode);
        }
        prevCode = code;
    }
    soundex.resize(4, '0');
}
 
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    std::string soundex(1, toupper(name[0]));
    createSoundexCode(soundex, name);
    return soundex;
}
