/**
 * @file tests.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Tests main file.
 * @version 0.1
 * @date 2023-05-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "gtest/gtest.h"


TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}


TEST(sample_test_case2, sample_test2)
{
    EXPECT_EQ(1, 12);
}

int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}