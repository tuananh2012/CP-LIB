#include "gtest/gtest.h"
#include "disjoint_set/disjoint_set.h"

TEST(TestDisjointSet, TestDisjointSet)
{
    DisjointSet s(5);
    s.Join(1, 2);
    s.Join(1, 3);
    s.Join(4, 5);
    vector<int> root(5);
    for (int i = 1; i <= 5; i++)
    {
        root[i] = s.FindRoot(i);
    }
    EXPECT_EQ(root[1], root[2]);
    EXPECT_EQ(root[3], root[2]);
    EXPECT_EQ(root[4], root[5]);
}