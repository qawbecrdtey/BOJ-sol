#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++) {
		cout << "VOTE " << t << ": THE";
		int n, m;
		cin >> n >> m;
		map<string, int> mp;
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			mp[move(s)] = 0;
		}
		for(int i = 0; i < m; i++) {
			string s1, s2;
			int d;
			cin >> s1 >> d >> s2;
			mp[move(s1)] += d;
		}
		if(n == 1) {
			cout << " WINNER IS " << mp.begin()->first << ' ' << mp.begin()->second << '\n';
			continue;
		}
		auto arr = new pair<string, int>[mp.size()];
		int idx = 0;
		for(auto it = mp.begin(); it != mp.end(); ++it, idx++) {
			arr[idx] = std::move(*it);
		}
		sort(arr, arr + idx, [](pair<string, int> const &a, pair<string, int> const &b) {
			return a.second > b.second;
		});
		if(arr[0].second != arr[1].second) {
			cout << " WINNER IS " << arr[0].first << ' ' << arr[0].second << '\n';
		}
		else {
			cout << "RE IS A DILEMMA\n";
		}
		delete[] arr;
	}
}