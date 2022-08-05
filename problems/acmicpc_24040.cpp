#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		long long n; cin >> n;
		if(n % 9 == 0) {
			cout << "TAK\n";
			continue;
		}
		if(n % 3 == 0) {
			cout << "NIE\n";
			continue;
		}
		if(n % 3 == 2) {
			cout << "TAK\n";
			continue;
		}
		cout << "NIE\n";
	}
}