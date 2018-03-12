#include "gtest/gtest.h"
#include "../../sum.h"
TEST(SumTest, Positive){
		EXPECT_EQ(5,Sum(2,3));
		EXPECT_EQ(7,Sum(3,4));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
