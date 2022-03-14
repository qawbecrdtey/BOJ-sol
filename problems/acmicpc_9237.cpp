#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, [](int a, int b) { return a > b; });
	int max = 0;
	for(int i = 0; i < n; i++) {
		if(max < i + 1 + a[i]) max = i + 1 + a[i];
	} cout << max + 1;
}