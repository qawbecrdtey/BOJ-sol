#include <iostream>
using namespace std;
int f(int n) {
	if(n == 1) return 1;
	return max(n, f((n & 1) ? (n * 3 + 1) : (n >> 1)));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; while(cin >> n) {
		if(!n) return 0;
		cout << f(n) << '\n';
	}
}