#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new pair<int, int>[n << 1];
	auto arr = new pair<int, int>[n];
	for(int i = 0; i < n; i++) {
		cin >> a[(i << 1)].first >> a[(i << 1) + 1].first;
		arr[i].first = a[i << 1].first;
		arr[i].second = a[(i << 1) + 1].first;
		a[i << 1].second = 0;
		a[(i << 1) + 1].second = 1;
	}
	sort(a, a + (n << 1));
	int max = 0;
	int maxi = 0;
	int cnt = 0;
	for(int i = 0; i < (n << 1); i++) {
		cnt += 1 - (a[i].second << 1);
		if(max < cnt) {
			max = cnt; maxi = i;
		}
	}
	cout << max << '\n';
	auto const piv = a[maxi].first;
	for(int i = 0; i < n; i++) {
		if(arr[i].first <= piv && arr[i].second >= piv) {
			cout << i + 1 << ' ';
		}
	}
	delete[] a;
	delete[] arr;
}