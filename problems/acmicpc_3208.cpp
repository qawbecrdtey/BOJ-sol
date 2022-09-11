#include <iostream>
using namespace std;
int count(int n, int m) {
	if(!n || !m) return 0;
	return 1 + count(m, n - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int m, n; cin >> m >> n;
	cout << count(m, n) - 1;
}