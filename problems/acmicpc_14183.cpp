#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; while(cin >> n >> m) {
		if(!n && !m) return 0;
		auto a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		auto b = new int[n];
		int cnt = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) cin >> b[j];
			for(int j = 0; j < n; j++) {
				if(b[j] > a[j]) goto NO;
			} cnt++;
		NO:	continue;
		} cout << cnt << '\n';
		delete[] a;
		delete[] b;
	}
}