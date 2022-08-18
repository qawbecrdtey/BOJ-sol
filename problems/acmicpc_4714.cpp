#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(2);
	cout << fixed;
	long double n; while(cin >> n) {
		if(n == -1.0) return 0;
		cout << "Objects weighing " << n << " on Earth will weigh " << n * 0.167 << " on the moon.\n";
	}
}