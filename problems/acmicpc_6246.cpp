#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto arr = new bool[n + 1]();
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		for(int j = a; j <= n; j += b) arr[j] = true;
	}
	int res = 0;
	for(int i = 1; i <= n; i++) res += arr[i];
	cout << n - res;
}