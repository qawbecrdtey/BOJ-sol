#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, t = 1; while(cin >> n) {
		if(!n) return 0;
		auto a = new int[n];
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		int const x = sum / n;
		int res = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] > x) res += a[i] - x;
		} delete[] a;
		cout << "Set #" << t++ << "\nThe minimum number of moves is " << res << ".\n\n";
	}
}