#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll dist(pll const &a, pll const &b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<ll, pll>[n];
	auto v = new vector<int>[n];
	for(int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a[i].second.first, &a[i].second.second, &a[i].first);
		for(int j = 0; j < i; j++) {
			auto const d = dist(a[i].second, a[j].second);
			if(a[j].first * a[j].first >= d) {
				v[j].push_back(i);
			}
			if(a[i].first * a[i].first >= d) {
				v[i].push_back(j);
			}
		}
	}
	delete[] a;
	auto cnt = new int[n]();
	for(int i = 0; i < n; i++) {
		auto visited = new bool[n]();
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			auto const now = q.front(); q.pop();
			if(visited[now]) continue;
			visited[now] = true;
			cnt[i]++;
			for(auto next : v[now]) {
				if(!visited[next]) q.push(next);
			}
		}
		delete[] visited;
	}
	int max = 0;
	for(int i = 0; i < n; i++) {
		if(max < cnt[i]) max = cnt[i];
	}
	printf("%d", max);
	delete[] cnt;
	delete[] v;
}