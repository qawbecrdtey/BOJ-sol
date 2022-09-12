#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; map<int, int> m; while(n--) {
		int x; cin >> x; m[x]++;
	} cout << max_element(m.begin(), m.end(), [](pair<int, int> const &a, pair<int, int> const &b) {
		return a.second < b.second;
	})->second;
}