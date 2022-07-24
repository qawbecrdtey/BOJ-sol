#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int a, b; cin >> a >> b;
		if(b != (__builtin_popcount(a) & 1)) cout << "Corrupt\n";
		else cout << "Valid\n";
	}
}