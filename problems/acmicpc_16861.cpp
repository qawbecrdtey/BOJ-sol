#include <iostream>
using namespace std;
inline bool f(int n) {
	int x = n, sum = 0;
	while(x) {
		sum += x % 10;
		x /= 10;
	} return n % sum == 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	while(n) {
		if(f(n)) {
			cout << n;
			return 0;
		} n++;
	}
}