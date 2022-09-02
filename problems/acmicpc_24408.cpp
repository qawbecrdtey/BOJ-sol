#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int start = 0, idx = 1;
	do {
		while(idx < n && a[idx] % a[start]) idx++;
		if(idx == n) break;
		cout << a[idx++] << '\n';
		start = idx++;
	} while(idx < n);
	delete[] a;
}