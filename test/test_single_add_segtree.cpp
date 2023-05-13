#include "segment_tree/basic_st.h"
#include "gtest/gtest.h"
TEST(TestSegmentTree, TestSegmentTree)
{
    std::vector<int> a= {1,2,3,4,5,6};
    SingleAddSegmentTree st(a);
    st.Build(0,0,5);
    EXPECT_EQ(st.Query(0,1), 3);
    EXPECT_EQ(st.Query(1,3), 9);
    EXPECT_EQ(st.Query(0,5), 21);
    st.Add(0, 0, 5, 2, 2);
    EXPECT_EQ(st.Query(2,2), 5);
    EXPECT_EQ(st.Query(1,2), 7);
    EXPECT_EQ(st.Query(0,5), 23);
}