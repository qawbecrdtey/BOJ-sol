#include <iostream>
#include <set>
#include <string>
using namespace std;
void dfs(int a[5][5], set<string> s[5][5][6], int i, int j, int depth) {
	if(!s[i][j][depth].empty()) return;
	if(depth == 5) {
		s[i][j][depth].insert(to_string(a[i][j]));
		return;
	}
	string prefix = to_string(a[i][j]);
	if(i) {
		dfs(a, s, i - 1, j, depth + 1);
		for(auto const &str : s[i - 1][j][depth + 1]) {
			s[i][j][depth].insert(prefix + str);
		}
	}
	if(j) {
		dfs(a, s, i, j - 1, depth + 1);
		for(auto const &str : s[i][j - 1][depth + 1]) {
			s[i][j][depth].insert(prefix + str);
		}
	}
	if(i < 4) {
		dfs(a, s, i + 1, j, depth + 1);
		for(auto const &str : s[i + 1][j][depth + 1]) {
			s[i][j][depth].insert(prefix + str);
		}
	}
	if(j < 4) {
		dfs(a, s, i, j + 1, depth + 1);
		for(auto const &str : s[i][j + 1][depth + 1]) {
			s[i][j][depth].insert(prefix + str);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a[5][5];
	for(auto &i : a) {
		for(auto &j : i) {
			cin >> j;
		}
	}
	set<string> s[5][5][6];
	set<string> res;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			dfs(a, s, i, j, 0);
			res.insert(s[i][j][0].begin(), s[i][j][0].end());
		}
	} cout << res.size();
}