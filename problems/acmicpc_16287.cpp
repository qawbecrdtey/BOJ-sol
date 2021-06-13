#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;
using namespace std;
int main() {
	ll w, n;
	cin >> w >> n;
	auto a = new ll[n];
	auto weight = new bool[w]();
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i] + a[j] < w - 1 && weight[w - a[i] - a[j]]) {
				cout << "YES";
				return 0;
			}
		}
		for(int j = 0; j < i; j++) {
			if(a[i] + a[j] < w - 1) weight[a[i] + a[j]] = true;
		}
	}
	cout << "NO";
	delete[] a;
}