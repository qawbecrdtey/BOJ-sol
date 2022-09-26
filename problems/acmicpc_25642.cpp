#include <iostream>
using namespace std;
static constexpr char const *c[2]{ "yt", "yj" };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a[2]; cin >> a[0] >> a[1];
	int x = 0;
	while(true) {
		a[1 - x] += a[x];
		if(a[1 - x] > 4) {
			cout << c[x];
			return 0;
		} x = 1 - x;
	}
}