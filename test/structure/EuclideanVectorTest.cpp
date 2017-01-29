#include <gtest/gtest.h>

#include "structure/EuclideanVector.h"

TEST (EuclideanVectorTest, Construct)
{
	EuclideanVector<double> mock(12, 5);
	EXPECT_DOUBLE_EQ(13, mock.getMagnitude());
	EXPECT_DOUBLE_EQ(22.6199, mock.getDirection());
	
	EuclideanVector<double> mock2(-10, 4);
	EXPECT_DOUBLE_EQ(10.7703, mock2.getMagnitude());
	EXPECT_DOUBLE_EQ(158.198, mock2.getDirection());

	EuclideanVector<double> mock3(-14, -7);
	EXPECT_DOUBLE_EQ(15.526, mock3.getMagnitude());
	EXPECT_DOUBLE_EQ(-153.434, mock3.getDirection());

	EuclideanVector<double> mock4(3, -11);
	EXPECT_DOUBLE_EQ(11.4018, mock4.getMagnitude());
	EXPECT_DOUBLE_EQ(105.255, mock4.getDirection());
}

TEST (EuclideanVectorTest, Addition)
{
	EuclideanVector<double> mock(12, 5);
	EuclideanVector<double> mock2(-10, 4);
	
	EuclideanVector<double> mock3 = mock + mock2;

	EXPECT_EQ(2, mock3.getX());
	EXPECT_EQ(9, mock3.getY());
}

TEST (EuclideanVectorTest, Subtract)
{
	EuclideanVector<double> mock(12, 5);
	EuclideanVector<double> mock2(6, 4);
	
	EuclideanVector<double> mock3 = mock - mock2;

	EXPECT_EQ(6, mock3.getX());
	EXPECT_EQ(1, mock3.getY());
}

TEST (EuclideanVectorTest, Normalize)
{
	EuclideanVector<double> mock(12, 5);

	mock.normalize();

	EXPECT_EQ(0.923077, mock.getX());
	EXPECT_EQ(0.384615, mock.getY());
}
