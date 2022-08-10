#include <iostream>
using namespace std;
inline int count(int a, int n) {
	return (a % 10 == n) || (a / 10 == n);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	int cnt = 0;
	while(a != c || b != d) {
		int const x = (count(a, e) || count(b, e));
		cnt += x;
		b++; if(b >= 60) b = 0, a++;
	} int const x = (count(a, e) || count(b, e));
	cnt += x;
	cout << cnt;
}