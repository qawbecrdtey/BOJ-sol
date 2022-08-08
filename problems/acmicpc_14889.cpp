#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int const m = (n >> 1);
	int res = 999999999;
	for(int i = 0; i < (1 << n); i++) {
		if(__builtin_popcount(i) != m) continue;
		vector<int> v, u;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) v.push_back(j);
			else u.push_back(j);
		}
		int sumv = 0, sumu = 0;
		for(int j = 0; j < m; j++) {
			for(int k = j + 1; k < m; k++) {
				sumv += a[v[j]][v[k]] + a[v[k]][v[j]];
				sumu += a[u[j]][u[k]] + a[u[k]][u[j]];
			}
		}
		int const r = abs(sumv - sumu);
		if(res > r) res = r;
	} cout << res;
}