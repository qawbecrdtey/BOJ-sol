#include <iostream>
using namespace std;
inline int convert(int n) {
	int res = 0;
	while(n) {
		res += n % 10;
		n /= 10;
	} return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; while(cin >> n) {
		if(!n) return 0;
		while(n >= 10) {
			n = convert(n);
		} cout << n << '\n';
	}
}