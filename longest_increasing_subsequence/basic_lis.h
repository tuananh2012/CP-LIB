#include <bits/stdc++.h>
template<typename T = int>
class BasicLis{
	private:
		std::vector<T> a;
	public:
		void MoveConstructor(std::vector<T> &x){
			a = std::move(x);
		}

		void CopyConstructor(std::vector<T> &x){
			a = x;
		}

		int FindLis(){
			int n = a.size();
			std::vector<int> d(n+1, std::numeric_limits<T>::max()); // d[i] = end element of lis len i;
			d[0] = std::numeric_limits<T>::min()
			int res = 1;
			for(int i = 0; i < n;i++){
				int cur = std::lower_bound(d.begin(), d.end(), a[i]) - d.begin();
				res = max(res, cur);
				d[cur] = std::min(d[cur] , a[i]);
			}
			return res;
		}
}
