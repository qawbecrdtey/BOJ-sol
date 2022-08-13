#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, i; cin >> n;
	auto a = new int[n];
	for(i = 0; i < n; i++) cin >> a[i];
	for(i = n - 1; i; i--) if(a[i - 1] > a[i]) break;
	cout << i;
}