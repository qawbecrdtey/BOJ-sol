#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, r{}; cin >> n;
	auto a = new int[n + 1];
	for(int i = 0; i < n + 1; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		int x; cin >> x; r += (a[i] + a[i + 1]) * x;
	} cout << r / 2; if(r & 1) cout << ".5";
}