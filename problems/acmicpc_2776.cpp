#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n; unordered_set<int> s;
		for(int i = 0; i < n; i++) {
			int x; cin >> x; s.insert(x);
		}
		int m; cin >> m;
		for(int i = 0; i < m; i++) {
			int x; cin >> x;
			cout << (s.find(x) != s.end()) << '\n';
		}
	}
}