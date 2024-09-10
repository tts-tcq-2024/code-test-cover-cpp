#include <gtest/gtest.h>
#include "Soundex.h"

// Test for generateSoundex
TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex("Example"), "E251");
    EXPECT_EQ(generateSoundex("Soundex"), "S532");
    EXPECT_EQ(generateSoundex("HWY"), "H000");
    EXPECT_EQ(generateSoundex(""), "");
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Abcd"), "A123");
    EXPECT_EQ(generateSoundex("pfister"), "P236");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
}

