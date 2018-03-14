#include "gtest/gtest.h"
#include "../../MathFunctions/MathFunctions.h"

TEST(MathTest, Correct){
		EXPECT_EQ(2.0,mysqrt(4.0));
		EXPECT_EQ(3.0,mysqrt(9.0));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
