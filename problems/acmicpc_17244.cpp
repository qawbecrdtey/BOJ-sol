#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> m >> n;
	auto a = new string[n];
	pair<int, int> start, end;
	vector<pair<int, int>> items;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'X') items.emplace_back(i, j);
			else if(a[i][j] == 'S') start = { i, j };
			else if(a[i][j] == 'E') end = { i, j };
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> q; // dist, cnt, x, y
	q.push({ {}, start });
	vector<vector<vector<bool>>> visited((1 << items.size()), vector<vector<bool>>(n, vector<bool>(m)));
	while(!q.empty()) {
		auto [info, pos] = q.front(); q.pop();
		if(visited[info.second][pos.first][pos.second]) continue;
		visited[info.second][pos.first][pos.second] = true;
		if(info.second == (1 << items.size()) - 1 && pos == end) {
			cout << info.first;
			return 0;
		}
		int const next_dist = info.first + 1;
		int const next_cnt = info.second | (a[pos.first][pos.second] == 'X' ? (1 << (find(items.begin(), items.end(), pos) - items.begin())) : 0);
		pair<int, int> next_info = {next_dist, next_cnt};
		if(pos.first && a[pos.first - 1][pos.second] != '#' && !visited[next_cnt][pos.first - 1][pos.second]) q.push({next_info, {pos.first - 1, pos.second}});
		if(pos.second && a[pos.first][pos.second - 1] != '#' && !visited[next_cnt][pos.first][pos.second - 1]) q.push({next_info, {pos.first, pos.second - 1}});
		if(pos.first < n - 1 && a[pos.first + 1][pos.second] != '#' && !visited[next_cnt][pos.first + 1][pos.second]) q.push({next_info, {pos.first + 1, pos.second}});
		if(pos.second < m - 1 && a[pos.first][pos.second + 1] != '#' && !visited[next_cnt][pos.first][pos.second + 1]) q.push({next_info, {pos.first, pos.second + 1}});
	}
}