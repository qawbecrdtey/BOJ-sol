#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool find(vector<int> const *v, bool *visited, int now, int to) {
	visited[now] = true;
	if(now == to) return true;
	return any_of(v[now].begin(), v[now].end(), [v, visited, to](int next) {
		return !visited[next] && find(v, visited, next, to);
	});
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pair<int, int>> interval;
	auto v = new vector<int>[n];
	auto visited = new bool[n];
	for(int t = 0; t < n; t++) {
		int a, b, c; cin >> a >> b >> c;
		if(a == 1) {
			for(int i = 0; i < interval.size(); i++) {
				if((b < interval[i].first && interval[i].first < c) || (b < interval[i].second && interval[i].second < c)) v[i].push_back(interval.size());
				if((interval[i].first < b && b < interval[i].second) || (interval[i].first < c && c < interval[i].second)) v[interval.size()].push_back(i);
			} interval.emplace_back(b, c);
		} else {
			fill(visited, visited + n, false);
			cout << find(v, visited, b - 1, c - 1) << '\n';
		}
	}
}