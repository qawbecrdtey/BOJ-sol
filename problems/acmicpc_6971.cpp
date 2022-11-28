#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int x; cin >> x; cout << x << " is";
		vector<pair<int, int>> v;
		for(int i = 1; i * i <= x; i++) {
			if(x % i) continue;
			v.emplace_back(i, x / i);
		}
		for(int i = 0; i < v.size(); i++) {
			for(int j = i; j < v.size(); j++) {
				if(v[i].second - v[i].first == v[j].first + v[j].second) goto END;
			}
		}
		cout << " not";
	END:cout << " nasty\n";
	}
}