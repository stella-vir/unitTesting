// g++ -std=c++11 -stdlib=libc++ -DGTEST_USE_OWN_TR1_TUPLE=1 google_test.cpp -o g
// clang++ -std=c++11 google_test.cpp -o g
// linker command failed g++ compiler for gcc


#include <gtest/gtest.h>

TEST(MyTestSuitName, MyTestCaseName) {
    int actual = 1;
    EXPECT_GT(actual, 0);
    EXPECT_EQ(1, actual) << "Should be equal to one";
}
