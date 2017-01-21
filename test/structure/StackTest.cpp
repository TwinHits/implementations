#include <gtest/gtest.h>

#include "structure/Stack.h"

Stack<int> StackMock;

TEST (StackTest, IntegerPush)
{
	StackMock.push(10);
	StackMock.push(9);
	StackMock.push(8);
	EXPECT_EQ(8, StackMock.peek());
}

TEST (StackTest, IntegerPop)
{
	EXPECT_EQ(8, StackMock.pop());
}

TEST (StackTest, IntegerPeek)
{
	EXPECT_EQ(9, StackMock.peek());
}
