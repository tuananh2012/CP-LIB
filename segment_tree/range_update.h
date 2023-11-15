#pragma once
#include <bits/stdc++.h>
template <typename T = int, T MAX_VALUE = 1e9>
class RangeUpdate
{
private:
    std::vector<T> data_;
    std::vector<T> st_;
    std::vector<bool> lazy_;
    int size_;

public:
    explicit RangeUpdate(std::vector<T> data)
    {
        size_ = data.size();
        data_ = std::move(data);
        st_.resize(4 * size_);
        lazy_.resize(4 * size_, false);
    }

    void Build(int id, int l, int r)
    {
        if (l == r)
        {
            st_[id] = data_[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(2 * id + 1, l, mid);
        Build(2 * id + 2, mid + 1, r);
        st_[id] = std::min(st_[2 * id + 1], st_[2 * id + 2]);
    }

    void PushDown(int id)
    {
        if (lazy_[id])
        {
            st_[2 * id + 1] = st_[id];
            st_[2 * id + 2] = st_[id];
            lazy_[2 * id + 1] = lazy_[2 * id + 2] = true;
        }
    }

    void RangeAssign(int id, int l, int r, int u, int v, T val)
    {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v)
        {
            st_[id] = val;
            lazy_[id] = true;
        }
        else
        {
            PushDown(id);
            auto mid = (l + r) >> 1;
            RangeAssign(2 * id + 1, l, mid, u, v, val);
            RangeAssign(2 * id + 2, mid + 1, r, u, v, val);
            st_[id] = std::min(st_[2 * id + 1], st_[2 * id + 2]);
        }
    }

    T Query(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return MAX_VALUE;
        if (l >= u && r <= v)
            return st_[id];
        else
        {
            int mid = (l + r) >> 1;
            PushDown(id);
            return std::min(Query(2 * id + 1, l, mid, u, v), Query(2 * id + 2, mid + 1, r, u, v));
        }
    }
};