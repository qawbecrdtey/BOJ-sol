#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; auto a = new int[n]; auto b = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	int const res = *max_element(a, a + n) - *min_element(b, b + n);
	cout << (res < 0 ? 0 : res);
}