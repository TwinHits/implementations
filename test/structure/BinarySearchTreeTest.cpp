#include <gtest/gtest.h>

#include "structure/BinarySearchTree.h"

BinarySearchTree<int> BSTMock;

TEST (BinartSearchTreeTest, IntegerInsert)
{
	BSTMock.insert(4);	
	BSTMock.insert(3);	
	BSTMock.insert(5);	
	BSTMock.insert(1);	
	BSTMock.insert(2);	
	BSTMock.insert(6);	

	EXPECT_TRUE(BSTMock.search(1));
	EXPECT_TRUE(BSTMock.search(2));
	EXPECT_TRUE(BSTMock.search(3));
	EXPECT_TRUE(BSTMock.search(4));
	EXPECT_TRUE(BSTMock.search(5));
	EXPECT_TRUE(BSTMock.search(6));
}

TEST (BinartSearchTreeTest, IntegerSearch)
{

	EXPECT_TRUE(BSTMock.search(1));
	EXPECT_TRUE(BSTMock.search(2));
	EXPECT_TRUE(BSTMock.search(3));
	EXPECT_TRUE(BSTMock.search(4));
	EXPECT_TRUE(BSTMock.search(5));
	EXPECT_TRUE(BSTMock.search(6));
}

TEST (BinartSearchTreeTest, TreeBalanced)
{
	EXPECT_TRUE(BSTMock.balanced());
	BSTMock.insert(7);
	BSTMock.insert(8);
	BSTMock.insert(9);
	EXPECT_FALSE(BSTMock.balanced());
}

TEST (BinartSearchTreeTest, TreeEquality)
{
	/**
	BinarySearchTree<int> Mock2;
	BSTMock.insert(4);	
	BSTMock.insert(3);	
	BSTMock.insert(5);	
	BSTMock.insert(1);	
	BSTMock.insert(2);	
	BSTMock.insert(6);	
	BSTMock.insert(7);
	BSTMock.insert(8);
	BSTMock.insert(9);

	EXPECT_EQ(Mock2, BSTMock);
**/
}

TEST (BinartSearchTreeTest, TreeAssignment)
{

}
