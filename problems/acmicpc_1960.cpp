#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	auto b = new int[n];
	auto arr = new int*[n];
	int suma = 0, sumb = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		suma += a[i];
		arr[i] = new int[n]();
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		sumb += b[i];
	}
	if(suma != sumb) {
		cout << -1;
		return 0;
	}
	auto c = new int[n];
	for(int i = 0; i < n; i++) c[i] = i;
	for(int i = 0; i < n; i++) {
		sort(c, c + n, [b](int x, int y){ return b[x] > b[y]; });
		for(int j = 0; j < n; j++) {
			if(a[i] && b[c[j]]) {
				arr[i][c[j]] = 1;
				a[i]--; b[c[j]]--;
				suma--; sumb--;
			}
		}
	} if(suma || sumb) { cout << -1; return 0; }
	cout << "1\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << arr[i][j];
		} cout << '\n';
	}

}