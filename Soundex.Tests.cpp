#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesSimpleCase) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
}

TEST(SoundexTest, HandlesDuplicateCodes) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}

TEST(SoundexTest, HandlesVowelsAndIgnoredLetters) {
    EXPECT_EQ(generateSoundex("Aeiouhwy"), "A000");
}

TEST(SoundexTest, HandlesVariousCases) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
    EXPECT_EQ(generateSoundex("Jackson"), "J250");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

TEST(SoundexTest, HandlesSimilarSoundingNames) {
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

TEST(SoundexTest, HandlesSameNumberSeparatedByVowel) {
    EXPECT_EQ(generateSoundex("Moses"), "M020");
    EXPECT_EQ(generateSoundex("Morris"), "M620");
}

TEST(SoundexTest, HandlesHAndWBetweenSameNumber) {
    EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
    EXPECT_EQ(generateSoundex("Tymchwak"), "T522");
}

TEST(SoundexTest, HandlesNameWithNoConsonants) {
    EXPECT_EQ(generateSoundex("AEIOUY"), "A000");
}

TEST(SoundexTest, PadsWithZerosIfNeeded) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Ab"), "A100");
    EXPECT_EQ(generateSoundex("Abc"), "A120");
}
