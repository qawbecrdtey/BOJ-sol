#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	auto b = new bool[400001]();
	int res = 0, j;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(j = 0; j < i; j++) {
			if(b[a[i] - a[j] + 200000]) {
				res++;
				break;
			}
		}
		for(j = 0; j <= i; j++) b[a[i] + a[j] + 200000] = true;
	}
	cout << res;
}