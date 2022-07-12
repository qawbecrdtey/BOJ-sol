#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		if(i % 10 != k % 10 && i % 10 != (k << 1) % 10) v.push_back(i);
	} cout << v.size() << '\n';
	for(int i : v) cout << i << ' ';
}