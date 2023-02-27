#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    int size_;
    vector<int> parent_;
    vector<int> sz_;

public:
    DisjointSet(int size)
    {
        size++;
        size_ = size;
        parent_.resize(size);
        sz_.resize(size);
        for (int i = 0; i < size_; i++)
        {
            parent_[i] = i;
            sz_[i] = 1;
        }
    }
    void Join(int u, int v);
    int FindRoot(int u);
};