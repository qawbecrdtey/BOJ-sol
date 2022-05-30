#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto arr = new int[n + 1]();
	while(m--) {
		int a, b, c; cin >> a >> b >> c;
		for(int i = a; i <= b; i++) arr[i] = c;
	}
	for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
}