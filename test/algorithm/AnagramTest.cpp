#include <gtest/gtest.h>

#include "algorithm/Anagram.h"

TEST (DISABLED_AnagramTest, Equality)
{
	Anagram("cinema", "iceman", 6);
}

TEST (DISABLED_AnagramTest, Inequality)
{

	Anagram("john", "literally anything else", 4);
	Anagram("john", "zach", 4);
}
