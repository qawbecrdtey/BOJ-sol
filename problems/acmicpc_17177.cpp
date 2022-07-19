#include <iostream>
using namespace std;
inline int sqrt(int n) {
	long long l = 0, r = n;
	while(l < r) {
		long long m = (l + r) >> 1;
		if(m * m == n) return (int)m;
		if(m * m < n) l = m + 1;
		else r = m;
	} return l;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c; cin >> c >> a >> b;
	if(c * c <= a * a + b * b) {
		cout << -1;
		return 0;
	}
	for(int i = 1; i < 100; i++) {
		if((c * c - a * a) * (c * c - b * b) == ((a * b) + (c * i)) * ((a * b) + (c * i))) {
			cout << i;
		}
	}
}