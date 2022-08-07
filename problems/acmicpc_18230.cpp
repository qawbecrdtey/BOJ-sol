#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, a, b, r; cin >> n >> a >> b;
	vector<int> va, vb; va.reserve(a); vb.reserve(a / 2 + b);
	for(int i = 0; i < a; i++) {
		int x; cin >> x; va.push_back(x);
	} sort(va.begin(), va.end(), [](int a, int b) { return a > b; });
	r = (n & 1) * va[0];
	for(int i = 0; i < (a - (n & 1)) / 2; i++) {
		vb.push_back(va[i * 2 + (n & 1)] + va[i * 2 + 1 + (n & 1)]);
	}
	for(int i = 0; i < b; i++) {
		int x; cin >> x; vb.push_back(x);
	} sort(vb.begin(), vb.end(), [](int a, int b) { return a > b; });
	n -= (n & 1); n >>= 1;
	for(int i = 0; i < n; i++) r += vb[i];
	cout << r;
}