#include <gtest/gtest.h>

#include "structure/DoubleLinkedList.h"


TEST (DoubleLinkedListTest, GetSize)
{
	DoubleLinkedList<int> mock;
	EXPECT_EQ(0, mock.getSize());
}

TEST (DoubleLinkedListTest, GetBeginIterator)
{
	DoubleLinkedList<int> mock;
	mock.insert(10);
	EXPECT_EQ(10, *(mock.begin()));
}

TEST (DoubleLinkedListTest, GetEndIterator)
{
	DoubleLinkedList<int> mock;
	mock.insert(10);
	mock.insert(9);
	mock.insert(8);
	mock.insert(7);
	mock.insert(6);
	EXPECT_EQ(10, *(mock.end()));
}

TEST (DoubleLinkedListTest, InsertByValue)
{
	DoubleLinkedList<int> mock;
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

TEST (DoubleLinkedListTest, RemoveByValue)
{
	DoubleLinkedList<int> mock;
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

TEST (DoubleLinkedListTest, RemoveByIterator)
{
	DoubleLinkedList<int> mock;
	mock.insert(10);
	mock.insert(9);
	mock.insert(8);
	mock.insert(7);
	mock.insert(6);

	auto head = mock.begin();
	auto mid = head + 2;
	auto end = mock.end();
	mock.remove(head);
	mock.remove(mid);
	mock.remove(end);
	
	auto iter = mock.begin();
	EXPECT_EQ(7, *iter);
	EXPECT_EQ(9, *(iter + 1));
}
