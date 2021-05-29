#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
void f(vector<int> *v, bool *visited, stack<int> &s, int i) {
	if(visited[i]) return;
	visited[i] = true;
	for(auto now : v[i]) {
		f(v, visited, s, now);
	}
	s.push(i);
}
void g(vector<int> *v, bool *visited, vector<int> &vs, int i) {
	if(visited[i]) return;
	visited[i] = true;
	for(auto now : v[i]) {
		g(v, visited, vs, now);
	}
	vs.push_back(i);
}
int main() {
	int n, e;
	scanf("%d%d", &n, &e);
	auto v1 = new vector<int>[n + 1];
	auto v2 = new vector<int>[n + 1];
	for(int i = 0; i < e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	auto visited = new bool[n + 1]();
	stack<int> s;
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			f(v1, visited, s, i);
		}
	}
	delete[] visited;
	visited = new bool[n + 1]();
	vector<vector<int>> vvs;
	while(!s.empty()) {
		auto const now = s.top(); s.pop();
		if(visited[now]) continue;
		vector<int> vs;
		g(v2, visited, vs, now);
		sort(vs.begin(), vs.end());
		vvs.emplace_back(std::move(vs));
	}
	sort(vvs.begin(), vvs.end(), [](vector<int> const &a, vector<int> const &b) {
		return a[0] < b[0];
	});
	cout << vvs.size() << '\n';
	for(auto const &vs : vvs) {
		for(auto now : vs) {
			printf("%d ", now);
		}
		printf("-1\n");
	}
	delete[] v2;
	delete[] v1;
	delete[] visited;
}