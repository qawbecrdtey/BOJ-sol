#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; auto a = new string[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int res = 1;
	for(int i = 1; i < n; i++) {
		res += (a[i - 1] != a[i].substr(0, a[i - 1].size()));
	} cout << res;
}