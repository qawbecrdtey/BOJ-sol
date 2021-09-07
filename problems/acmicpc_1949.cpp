#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
inline int max(pair<int, int> const& p) { return p.first > p.second ? p.first : p.second; }
pair<int, int> dp(vector<int> const* v, int const* a, int now, int prev) {
	int off = 0;
	int on = a[now];
	for (auto next : v[now]) {
		if (next == prev) continue;
		auto const p = dp(v, a, next, now);
		on += p.first;
		off += max(p);
	}
	return { off, on };
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n + 1];
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	auto v = new vector<int>[n + 1];
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	printf("%d", max(dp(v, a, 1, 0)));
	delete[] v;
	delete[] a;
}