#include <gtest/gtest.h>

#include "structure/PriorityQueue.h"

PriorityQueue<int, int> PQMock;

TEST (PriorityQueueTest, IntegerPush)
{
	PQMock.push(1, 10);
	PQMock.push(2, 5);
	PQMock.push(3, 20);
	PQMock.push(4, 15);

	EXPECT_EQ(3, PQMock.peek());
}

TEST (PriorityQueueTest, IntegerPeek)
{
	EXPECT_EQ(3, PQMock.peek());
}

TEST (PriorityQueueTest, IntegerPop)
{
	EXPECT_EQ(3, PQMock.pop());
	EXPECT_EQ(4, PQMock.pop());
	EXPECT_EQ(1, PQMock.pop());
	EXPECT_EQ(2, PQMock.pop());
}

