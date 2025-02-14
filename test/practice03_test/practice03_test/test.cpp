#include <gtest/gtest.h>
#include "pch.h"
#include "main.cpp"


TEST(MathUtilsTest, SumRange) {
  EXPECT_EQ(MathUtils::sumRange(1, 5),10);
  EXPECT_EQ(MathUtils::sumRange(3, 3), 0);
  EXPECT_EQ(MathUtils::sumRange(-2, 2), 0);
 
}
TEST(MathUtilsTest, ContainsNegative) {
	EXPECT_TRUE(MathUtils::containsNegative({ 1,-2,3 }));
	EXPECT_FALSE(MathUtils::containsNegative({ 1,2,3 }));
	EXPECT_FALSE(MathUtils::containsNegative({ }));
	
}
TEST(MathUtilsTest, FindMax) {
	EXPECT_EQ(MathUtils::findMax({ 1,2,3,4 }),4);
	EXPECT_EQ(MathUtils::findMax({ 1,2,2 }),2);
	EXPECT_THROW(MathUtils::findMax({}), std::invalid_argument);
}

