#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int f(pair<int, int> const *v, map<int, pair<int, int>> &m, int cur, int curh, int left) {
	if(cur == -1) return left;
	int l = f(v, m, v[cur].first, curh + 1, left);
	if(!m[curh].first || m[curh].first > l) m[curh].first = l;
	m[curh].second = l;
	return f(v, m, v[cur].second, curh + 1, l + 1);
}
int main() {
	int n;
	scanf("%d", &n);
	auto v = new pair<int, int>[n + 1];
	auto visited = new bool[n + 1]();
	for(int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a] = make_pair(b, c);
		if(b != -1) visited[b] = true;
		if(c != -1) visited[c] = true;
	}
	auto root = 1;
	while(visited[root]) root++;
	delete[] visited;
	map<int, pair<int, int>> m;
	f(v, m, root, 1, 1);
	int max = 0;
	int maxh = 0;
	for(auto const &now : m) {
		if(now.second.second - now.second.first + 1 > max) {
			max = now.second.second - now.second.first + 1;
			maxh = now.first;
		}
	}
	printf("%d %d", maxh, max);
	delete[] v;
}