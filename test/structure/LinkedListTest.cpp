#include <gtest/gtest.h>

#include "structure/LinkedList.h"


TEST (LinkedListTest, GetSize)
{
	LinkedList<int> mock;
	EXPECT_EQ(0, mock.getSize());
}

TEST (LinkedListTest, GetBeginIterator)
{
	LinkedList<int> mock;
	mock.insert(10);
	EXPECT_EQ(10, *(mock.begin()));
}

TEST (LinkedListTest, InsertByValue)
{
	LinkedList<int> mock;
	mock.insert(10);
	mock.insert(9);
	mock.insert(8);
	mock.insert(7);
	mock.insert(6);
	
	EXPECT_EQ(5, mock.getSize());

	auto iter = mock.begin();
	for (int i = 6; i != 10; i++)
	{
		EXPECT_EQ(*iter, i);
		iter = iter + 1;
	}
}

TEST (LinkedListTest, RemoveByValue)
{
	LinkedList<int> mock;
	mock.insert(10);
	mock.insert(9);
	mock.insert(8);
	mock.insert(7);
	mock.insert(6);

	mock.remove(10);
	mock.remove(8);
	mock.remove(6);

	EXPECT_EQ(2, mock.getSize());

	auto iter = mock.begin();
	EXPECT_EQ(7, *iter);
	EXPECT_EQ(9, *(iter + 1));
}

TEST (LinkedListTest, RemoveByIterator)
{
	LinkedList<int> mock;
	mock.insert(10);
	mock.insert(9);
	mock.insert(8);
	mock.insert(7);
	mock.insert(6);

	auto head = mock.begin();
	auto mid = head + 2;
	auto end = head + 4;
	mock.remove(head);
	mock.remove(mid);
	mock.remove(end);
	
	auto iter = mock.begin();
	EXPECT_EQ(7, *iter);
	EXPECT_EQ(9, *(iter + 1));
}
 
TEST (LinkedListTest, RemoveByNode)
{

}
