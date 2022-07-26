#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int t; cin >> t;
	int idx = 0, res = t % a[0];
	for(int i = 1; i < n; i++) {
		if(res > t % a[i]) idx = i, res = t % a[i];
	} cout << a[idx];
}