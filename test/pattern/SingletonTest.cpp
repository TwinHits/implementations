#include <gtest/gtest.h>

#include "pattern/Singleton.h"

TEST (SingletonTest, OnlyEverOneObject)
{
	auto mockSingleton1 = Singleton<int>::Instance();
	auto mockSingleton2 = Singleton<int>::Instance();
	EXPECT_EQ(mockSingleton1, mockSingleton2);
}
