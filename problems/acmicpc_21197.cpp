#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	if(n & 1) {
		cout << "still running";
		return 0;
	} n >>= 1;
	int elapsed = 0;
	while(n--) {
		int a, b; cin >> a >> b;
		elapsed += b - a;
	} cout << elapsed;
}