#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m; m += 60;
	if(n <= m) cout << n * 1500;
	else cout << m * 1500 + (n - m) * 3000;
}