#include "segment_tree/range_update.h"
#include "gtest/gtest.h"
TEST(TestRMQ, TestRMQ)
{
    std::vector<int> data = {32, 4, 5, 6, 3, 6, 7};
    RangeUpdate<int, 100000> ru(data);
    ru.Build(0, 0, 6);

    auto do_test = [&]()
    {
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = i; j < data.size(); j++)
            {
                auto ans = *std::min_element(data.begin() + i, data.begin() + j + 1);
                EXPECT_EQ(ru.Query(0, 0, 6, i, j), ans);
            }
        }
    };
    do_test();
    ru.RangeAssign(0, 0, 6, 0, 2, 1);
    data[0] = data[1] = data[2] = 1;
    do_test();
    ru.RangeAssign(0, 0, 6, 3, 6, 100);
    for (int i = 3; i <= 6; i++)
    {
        data[i] = 100;
    }
    do_test();
}