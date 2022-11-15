#include <iostream>
#include <vector>
using namespace std;
inline int sign(int a, int b) {
	if(a < b) return 1;
	if(a == b) return 0;
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<vector<int>> v;
	v.reserve(n);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		vector<int> vv; vv.reserve(m);
		for(int j = 0; j < m; j++) {
			int x; cin >> x; vv.push_back(x);
		}
		for(auto &v_ : v) {
			bool flag = true;
			for(int j = 0; j < m - 1; j++) {
				for(int k = j + 1; k < m; k++) {
					if(sign(v_[j], v_[k]) != sign(vv[j], vv[k])) {
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}
			cnt += flag;
		}
		v.emplace_back(std::move(vv));
	} cout << cnt;
}