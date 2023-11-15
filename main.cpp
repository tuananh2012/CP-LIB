#include <bits/stdc++.h>
#include "disjoint_set/disjoint_set.h"
int main(){
	DisjointSet s(4);
	s.Join(1, 2);
	s.Join(2,3);
	std::cout << s.FindRoot(3);
}
