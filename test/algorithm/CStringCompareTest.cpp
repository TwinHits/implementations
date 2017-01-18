#include <gtest/gtest.h>

#include "algorithm/CStringCompare.h"

TEST (CStringCompareTest, Sucess)
{
	EXPECT_TRUE(CStringCompare("one", "one"));
	EXPECT_TRUE(CStringCompare("four", "four"));
	EXPECT_TRUE(CStringCompare( "fives", "fives"));
}

TEST (CStringCompareTest, Failure)
{
	EXPECT_FALSE(CStringCompare("one", "ote"));
	EXPECT_FALSE(CStringCompare("three", "one"));
	EXPECT_FALSE(CStringCompare("ones", "one"));
}

