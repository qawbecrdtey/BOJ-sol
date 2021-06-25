#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct uf {
	int *arr, *rank;
	uf(int n) : arr(new int[n + 1]), rank(new int[n + 1]) {
		for(int i = 1; i <= n; i++) arr[i] = i, rank[i] = 1;
	}
	~uf() { delete[] arr; delete[] rank; }
	int find(int x) {
		if(arr[x] == x) return x;
		return arr[x] = find(arr[x]);
	}
	void merge(int a, int b) {
		auto x = find(a);
		auto y = find(b);
		if(x == y) return;
		if(rank[x] > rank[y]) swap(x, y);
		arr[x] = y;
		if(rank[x] == rank[y]) rank[x]++;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	priority_queue<pair<int, pair<int, int>>> pq;
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		pq.push(make_pair(-c, make_pair(a, b)));
	}
	uf u(n);
	int cnt = 0;
	int sum = 0;
	while(!pq.empty()) {
		auto const now = pq.top(); pq.pop();
		if(u.check(now.second.first, now.second.second)) continue;
		if(cnt == n - 2) {
			printf("%d", sum);
			return 0;
		}
		u.merge(now.second.first, now.second.second);
		sum -= now.first;
		cnt++;
	}
}