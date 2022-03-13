#include <iostream>
#include <set>
using namespace std;
inline bool lucky(int n) {
	while(n) {
		int const x = n % 10;
		if(x != 5 && x != 8) return false;
		n /= 10;
	} return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m, k; cin >> n;
		auto a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cin >> m;
		auto b = new int[m];
		for(int i = 0; i < m; i++) cin >> b[i];
		cin >> k;
		auto c = new int[k];
		for(int i = 0; i < k; i++) cin >> c[i];
		set<int> s;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				for(int l = 0; l < k; l++) {
					if(lucky(a[i] + b[j] + c[l])) s.insert(a[i] + b[j] + c[l]);
				}
			}
		}
		cout << s.size() << '\n';
		delete[] a;
		delete[] b;
		delete[] c;
	}
}