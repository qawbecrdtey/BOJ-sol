#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline int result(vector<int> v) {
	while(v.size() > 1) {
		vector<int> a;
		for(int i = 1; i < v.size(); i++) {
			a.push_back(v[i - 1] + v[i]);
		} v = std::move(a);
	} return v[0];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, f; cin >> n >> f;
	vector<int> a(n); for(int i = 0; i < n; i++) a[i] = i + 1;
	do {
		if(f == result(a)) {
			for(int i = 0; i < n; i++) cout << a[i] << ' ';
			return 0;
		}
	} while(next_permutation(a.begin(), a.end()));
}