#include <bits/stdc++.h>
template <typename T = int>
class FenwickTree
{
private:
    std::vector<T> fen_;
    int size_;

public:
    explicit FenwickTree(int size)
    {
        fen_.resize(size + 1, 0); // 1_based_index
        size_ = size;
    }
    void add(int pos, T x)
    {
        for (int i = pos; i <= size_; i += (i & -i))
        {
            fen_[i] += x;
        }
    }
    T get_sum(int pos)
    {
        T sum = 0;
        for (int i = pos; i; i -= (i & -i))
        {
            sum += fen_[i];
        }
        return sum;
    }
};
