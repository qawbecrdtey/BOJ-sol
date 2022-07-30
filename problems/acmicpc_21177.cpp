#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; auto a = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} sort(a, a + n);
	int tot = 0, cur = a[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if(a[i] + 1 == cur) cur = a[i];
		else {
			tot += cur;
			cur = a[i];
		}
	} tot += cur;
	cout << tot;
}