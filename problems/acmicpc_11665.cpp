#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int one[3]{}, two[3];
	fill(two, two + 3, 9999);
	for(int i = 0; i < n; i++) {
		for(int &j : one) {
			int x; cin >> x; j = max(j, x);
		}
		for(int &j : two) {
			int x; cin >> x; j = min(j, x);
		}
	} int res = 1;
	for(int i = 0; i < 3; i++) {
		if(one[i] >= two[i]) {
			res = 0; break;
		} res *= two[i] - one[i];
	} cout << res;
}