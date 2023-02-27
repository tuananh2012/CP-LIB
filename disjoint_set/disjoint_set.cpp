#include "disjoint_set.h"

int DisjointSet::FindRoot(int u)
{
    if (u == parent_[u])
        return u;
    return parent_[u] = FindRoot(parent_[u]);
}

void DisjointSet::Join(int u, int v)
{
    u = FindRoot(u);
    v = FindRoot(v);
    if (sz_[u] < sz_[v])
    {
        parent_[u] = v;
        sz_[v] += sz_[u];
        return;
    }
    parent_[v] = u;
    sz_[u] += sz_[v];
}