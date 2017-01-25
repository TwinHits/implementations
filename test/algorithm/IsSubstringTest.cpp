#include <gtest/gtest.h>

#include "algorithm/IsSubstring.h"

TEST (SubStringTest, IsSubstringTrue)
{
	EXPECT_TRUE(IsSubstring("waterbottle", "bottle"));
	EXPECT_TRUE(IsSubstring("waterbottle", "water"));
	EXPECT_TRUE(IsSubstring("XxXxXxXe", "XxX"));
}

TEST (SubStringTest, IsSubstringFalse)
{
	EXPECT_FALSE(IsSubstring("waterbottle", "John"));
	EXPECT_FALSE(IsSubstring("waterbottle", "Literally anything elser"));
	EXPECT_FALSE(IsSubstring("XxXxXxX", "XxXxx"));
}
