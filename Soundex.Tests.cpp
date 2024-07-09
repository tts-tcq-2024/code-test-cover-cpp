#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
}

TEST(SoundexTest, HandlesBasicFunctionality) {
    EXPECT_EQ(generateSoundex("Smith"), "S530");
    EXPECT_EQ(generateSoundex("Smyth"), "S530");
}

TEST(SoundexTest, HandlesDifferentStartingLetters) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
}

TEST(SoundexTest, HandlesSimilarSounds) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
}

TEST(SoundexTest, HandlesDifferentLengths) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Al"), "A400");
    EXPECT_EQ(generateSoundex("Alii"), "A400");
}

