#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	vector<int> v; int x;
	while(cin >> x) {
		v.push_back(x);
	}
	int c = v.back(); v.pop_back();
	map<int, int> m;
	for(int vv : v) m[vv]++;
	int cnt = 0;
	for(auto [a, i] : m) {
		for(auto [b, j] : m) {
			if(a > b || a + b != c) continue;
			if(a == b && i <= 1) continue;
			cout << a << ' ' << b << '\n';
			cnt++;
		}
	} cout << cnt;
}