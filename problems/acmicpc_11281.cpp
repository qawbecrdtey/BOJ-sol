#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
inline int index(int x) {
	if(x > 0) return x << 1;
	return index(-x) - 1;
}
void dfs1(vector<int> const *v, stack<int> &s, bool *visited, int now) {
	visited[now] = true;
	for(auto next : v[now]) {
		if(!visited[next]) dfs1(v, s, visited, next);
	}
	s.push(now);
}
void dfs2(vector<int> const *u, vector<int> &scv, bool *visited, int now) {
	visited[now] = true;
	for(auto next : u[now]) {
		if(!visited[next]) dfs2(u, scv, visited, next);
	}
	scv.push_back(now);
}
inline int negative(int x) {
	if(x & 1) return x + 1;
	return x - 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto v = new vector<int>[n * 2 + 1];
	auto u = new vector<int>[n * 2 + 1];
	while(m--) {
		int x, y;
		cin >> x >> y;
		v[index(-x)].push_back(index(y));
		v[index(-y)].push_back(index(x));
		u[index(x)].push_back(index(-y));
		u[index(y)].push_back(index(-x));
	}
	auto visited = new bool[n * 2 + 1]();
	stack<int> s;
	for(int i = 1; i <= n * 2; i++) {
		if(!visited[i]) dfs1(v, s, visited, i);
	}
	fill(visited, visited + n * 2 + 1, false);
	vector<vector<int>> scc;
	auto value = new int[n * 2 + 1]();
	int cnt = 1;
	while(!s.empty()) {
		auto const now = s.top(); s.pop();
		if(visited[now]) continue;
		vector<int> scv;
		dfs2(u, scv, visited, now);
		for(auto val : scv) {
			value[val] = cnt;
		} cnt++;
		scc.emplace_back(move(scv));
	}
	for(int i = 1; i <= n; i++) {
		if(value[i * 2 - 1] == value[i * 2]) {
			cout << 0;
			return 0;
		}
	}
	cout << "1\n";
	auto res = new int[n * 2 + 1]();
	for(auto const &scv : scc) {
		for(auto val : scv) {
			if(res[val]) {
				for(auto val1 : scv) {
					res[val1] = 1;
					res[negative(val1)] = 0;
				}
				break;
			}
			res[negative(val)] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << res[i * 2] << ' ';
	}
	delete[] res;
	delete[] value;
	delete[] visited;
	delete[] v;
	delete[] u;
}