#include <bits/stdc++.h>

template <typename T>
class SingleAddSegmentTree
{ // sum range query
private:
    std::vector<T> data_;
    std::vector<T> st_;
    int size_;

public:
    explicit SingleAddSegmentTree(int size) : size_(size)
    {
        data_.resize(size);
        st_.resize(4 * size);
    }
    explicit SingleAddSegmentTree(std::vector<T> data)
    {
        size_ = data.size();
        st_.resize(4 * size_);
        data_ = std::move(data);
    }

    int get_left_child(int id)
    {
        return (id << 1) | 1 ;
    }

    int get_right_child(int id)
    {
        return (id + 1) << 1;
    }

    void Build(int id, int l, int r)
    {
        if (l == r){
            st_[id] = data_[l];
            return;
        }
        auto mid = (l + r) >> 1;
        Build(get_left_child(id), l, mid);
        Build(get_right_child(id), mid + 1, r);
        st_[id] = st_[get_left_child(id)] + st_[get_right_child(id)];
    }

    void Add(int id, int l, int r, int pos, int val)
    {
        if (l > pos || r < pos)
            return;
        if (l == r && r == pos)
        {
            st_[id] += val;
        }
        auto mid = (l + r) >> 1;
        Add(get_left_child(id), l, mid, pos, val);
        Add(get_right_child(id), mid + 1, r, pos, val);
        st_[id] = st_[get_left_child(id)] + st_[get_right_child(id)];
    }

    T Query(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return 0;
        }
        if (l == r)
            return st_[id];
        auto mid = (l + r) >> 1;
        return Query(get_left_child(id), l, mid, u, v) + Query(get_right_child(id), mid + 1, r, u, v);
    }
    T Query(int u, int v)
    {
        return Query(0, 0, size_ - 1, u, v);
    }
};