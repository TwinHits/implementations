#include <gtest/gtest.h>

#include "structure/Queue.h"

Queue<int> QueueMock;

TEST (QueueTest, IntegerPush)
{
	QueueMock.push(1);
	QueueMock.push(2);
	QueueMock.push(3);
	QueueMock.push(4);

	EXPECT_EQ(1, QueueMock.peek());
}

TEST (QueueTest, IntegerPeek)
{
	EXPECT_EQ(1, QueueMock.peek());
}

TEST (QueueTest, IntegerPop)
{
	EXPECT_EQ(1, QueueMock.pop());
	EXPECT_EQ(2, QueueMock.pop());
	EXPECT_EQ(3, QueueMock.pop());
	EXPECT_EQ(4, QueueMock.pop());
}
