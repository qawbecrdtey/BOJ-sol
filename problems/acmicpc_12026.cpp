#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
constexpr int M = numeric_limits<int>::max();
inline bool next(char c, char d) {
	return (c == 'B' && d == 'O') || (c == 'O' && d == 'J') || (c == 'J' && d == 'B');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	auto a = new int[n]; fill(a + 1, a + n, M); a[0] = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == M) continue;
		for(int j = i + 1; j < n; j++) {
			if(next(s[i], s[j])) {
				a[j] = min(a[j], a[i] + (j - i) * (j - i));
			}
		}
	} cout << (a[n - 1] == M ? -1 : a[n - 1]);
}