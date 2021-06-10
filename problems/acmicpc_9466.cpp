#include <stdio.h>
#include <utility>
using namespace std;
int f(int const *a, bool *visited, pair<int, int> *cur, int stage, int idx, int cnt) {
	if(visited[idx]) {
		if(cur[idx].first != stage) return 0;
		return cnt - cur[idx].second;
	}
	visited[idx] = true;
	cur[idx].first = stage;
	cur[idx].second = cnt;
	return f(a, visited, cur, stage, a[idx], cnt + 1);
}
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n;
		scanf("%d", &n);
		auto a = new int[n + 1];
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		auto visited = new bool[n + 1]();
		auto cur = new pair<int, int>[n + 1]();
		int sum = 0;
		int stage = 0;
		for(int i = 1; i <= n; i++) {
			if(visited[i]) continue;
			sum += f(a, visited, cur, ++stage, i, 1);
		}
		printf("%d\n", n - sum);
		delete[] cur;
		delete[] visited;
		delete[] a;
	}
}