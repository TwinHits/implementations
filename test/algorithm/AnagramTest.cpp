#include <gtest/gtest.h>

#include "algorithm/Anagram.h"

TEST (AnagramTest, Equality)
{
	char first[] = "cinema";
	char second[] = "iceman";
	EXPECT_TRUE(Anagram(first, second, 6));
}

TEST (AnagramTest, Inequality)
{

	char first[] = "john";
	char second[] = "zach";
	char third[] = "literally anything else";
	EXPECT_FALSE(Anagram(first, second, 4));
	EXPECT_FALSE(Anagram(first, third, 4));
}
