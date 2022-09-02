#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		long long a, b, c, d; cin >> a >> b >> c >> d;
		if(abs(a - b) % (c + d)) cout << "-1\n";
		else cout << abs(a - b) / (c + d) << '\n';
	}
}