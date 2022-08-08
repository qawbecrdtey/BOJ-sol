#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, n; cin >> a >> b >> n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
	}
	int mul = 1; int val = 0;
	for(auto it = v.rbegin(); it != v.rend(); ++it) {
		val += mul * *it;
		mul *= a;
	} v.clear();
	while(val) {
		v.push_back(val % b);
		val /= b;
	}
	for(auto it = v.rbegin(); it != v.rend(); ++it) {
		cout << *it << ' ';
	}
}