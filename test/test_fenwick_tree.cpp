#include "fenwick_tree/fenwick_tree.h"
#include "gtest/gtest.h"

TEST(TestFenwick, TestFenwick)
{
    FenwickTree a(10);
    a.add(5, 1);
    a.add(2, 3);
    EXPECT_EQ(a.get_sum(5), 4);
    EXPECT_EQ(a.get_sum(4), 3);
    EXPECT_EQ(a.get_sum(2), 3);
    EXPECT_EQ(a.get_sum(1), 0);



}