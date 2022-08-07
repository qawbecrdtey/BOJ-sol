#include <iostream>
#include <set>
using namespace std;
inline int next(int n) {
	int const x = n * n;
	return (x / 100) % 10000;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; while(cin >> n) {
		if(!n) return 0;
		set<int> s;
		int cnt = 0;
		while(s.insert(n).second) {
			n = next(n);
			cnt++;
		}
		cout << cnt << '\n';
	}
}