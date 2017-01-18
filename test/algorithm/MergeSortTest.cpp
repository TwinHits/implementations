#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "algorithm/CStringCompare.h"
#include "algorithm/MergeSort.h"

TEST (MergeSortTest, IntegerEvenSize)
{
	int SortArray[] = {89, 29, 61, 26, 45, 38, 57, 7, 44, 73, 2, 64, 55, 10, 12, 54, 58, 17, 27, 82, 47, 51, 15, 21, 59, 8, 68, 75, 65, 19, 86, 95, 78, 52, 39, 71, 35, 76, 9, 70, 84, 5, 67, 14, 93, 43, 49, 99, 48, 42};
	int ExpectedArray[] = {2, 5, 7, 8, 9, 10, 12, 14, 15, 17, 19, 21, 26, 27, 29, 35, 38, 39, 42, 43, 44, 45, 47, 48, 49, 51, 52, 54, 55, 57, 58, 59, 61, 64, 65, 67, 68, 70, 71, 73, 75, 76, 78, 82, 84, 86, 89, 93, 95, 99};
	MergeSort(SortArray, 0, 49);
	EXPECT_THAT(ExpectedArray, testing::ContainerEq(SortArray));
}

TEST (MergeSortTest, IntegerOddSize)
{
	int SortArray[] = {70, 31, 40, 81, 37, 60, 1, 89, 34, 66, 23, 16, 19, 14, 50, 6, 49, 86, 43, 48, 94, 93, 13, 85, 21, 72, 7, 88, 25, 54, 79, 95, 55, 9, 11, 30, 65, 87, 10, 57, 24, 58, 90, 35, 59, 62, 17, 44, 15};
	int ExpectedArray[] = {1, 6, 7, 9, 10, 11, 13, 14, 15, 16, 17, 19, 21, 23, 24, 25, 30, 31, 34, 35, 37, 40, 43, 44, 48, 49, 50, 54, 55, 57, 58, 59, 60, 62, 65, 66, 70, 72, 79, 81, 85, 86, 87, 88, 89, 90, 93, 94, 95};
	MergeSort(SortArray, 0, 48);
	EXPECT_THAT(ExpectedArray, testing::ContainerEq(SortArray));
}

TEST (MergeSortTest, CharEvenSize)
{
	char SortString[] = "TwinHits";
	char ExpectedString[] = "HTiinstw";
	MergeSort(SortString, 0, 7);
	EXPECT_TRUE(CStringCompare(ExpectedString, SortString));
}

TEST (MergeSortTest, CharOddSize)
{
	char SortString[] = "TwinHit";
	char ExpectedString[] = "HTiintw";
	MergeSort(SortString, 0, 6);
	EXPECT_TRUE(CStringCompare(ExpectedString, SortString));
}
