#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "algorithm/QuickSelect.h"

TEST (QuickSelectTest, IntegerEvenSize)
{
	int selectArray[] = {4,1,2,5,3,10,8,9,6,19,20,11,12,15,16,17,13,14};
	int expectedInt = 9;
	EXPECT_EQ(expectedInt, QuickSelect(selectArray, 8, 0, 19));
}

TEST (QuickSelectTest, IntegerOddSize)
{
	int selectArray[] = {4,1,2,5,3,10,8,9,6,19,11,12,15,16,17,13,14};
	int expectedInt = 2; 
	EXPECT_EQ(expectedInt, QuickSelect(selectArray, 1, 0, 18));
}

TEST (QuickSelectTest, CharEvenSize)
{
	char selectString[] = "TwinHits";
	char expectedChar = 'H';
	EXPECT_EQ(expectedChar, QuickSelect(selectString, 0, 0, 7));
}

TEST (QuickSelectTest, CharOddSize)
{
	char selectString[] = "TwinHit";
	char expectedChar = 'w';
	EXPECT_EQ(expectedChar, QuickSelect(selectString, 6, 0, 6));
}
