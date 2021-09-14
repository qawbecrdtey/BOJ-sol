#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	auto orig = new int*[n];
	for(int i = 0; i < n; i++) {
		orig[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> orig[i][j];
		}
	}
	int min = -1;
	for(int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		auto a = new int*[n];
		for(int j = 0; j < n; j++) {
			a[j] = new int[n];
			copy(orig[j], orig[j] + n, a[j]);
		}
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				cnt++;
				a[0][j] = 1 - a[0][j];
				a[1][j] = 1 - a[1][j];
				if(j) a[0][j - 1] = 1 - a[0][j - 1];
				if(j < n - 1) a[0][j + 1] = 1 - a[0][j + 1];
			}
		}
		for(int j = 1; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(a[j - 1][k]) {
					cnt++;
					a[j - 1][k] = 1 - a[j - 1][k];
					a[j][k] = 1 - a[j][k];
					if(k) a[j][k - 1] = 1 - a[j][k - 1];
					if(k < n - 1) a[j][k + 1] = 1 - a[j][k + 1];
					if(j < n - 1) a[j + 1][k] = 1 - a[j + 1][k];
				}
			}
		}
		for(int j = 0; j < n; j++) {
			if(a[n - 1][j]) goto END;
		}
		if(min == -1 || min > cnt) min = cnt;
	END:for(int j = 0; j < n; j++) delete[] a[j];
		delete[] a;
	}
	cout << min;
	delete[] orig;
}