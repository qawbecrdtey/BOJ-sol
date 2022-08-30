#include <array>
#include <iostream>
#include <string>
using namespace std;
constexpr int M = 1 << 30;
inline bool f(int n, int m) {
	string s, t;
	for(int i = 0; i < 32; i++) {
		if(n & (1 << i)) s.push_back((char)(i + 1));
		if(m & (1 << i)) t.push_back((char)(i + 1));
	} return s > t;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; array<int, 4> m; for(int &i : m) cin >> i;
	auto a = new array<int, 5>[n];
	for(int i = 0; i < n; i++) {
		for(int &j : a[i]) cin >> j;
	} int res = M, resi = 0;
	for(int i = 1; i < (1 << n); i++) {
		int cost = 0;
		array<int, 4> val{};
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				for(int k = 0; k < 4; k++) {
					val[k] += a[j][k];
				} cost += a[j][4];
			}
		}
		if(val[0] >= m[0] && val[1] >= m[1] && val[2] >= m[2] && val[3] >= m[3]) {
			if(cost < res || (cost == res && f(resi, i))) res = cost, resi = i;
		}
	}
	if(res == M) cout << -1;
	else {
		cout << res << '\n';
		for(int i = 0; i < n; i++) {
			if(resi & (1 << i)) cout << i + 1 << ' ';
		}
	}
}