#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
void dfs(vector<pair<int, long double>> v[4], long double a[4], int t, int cur_time, int cur, long double val) {
	if(cur_time == t) {
		a[cur] += val;
		return;
	}
	for(auto const &next : v[cur]) {
		dfs(v, a, t, cur_time + 1, next.first, val * next.second);
	}
}
int main() {
	int t, m;
	scanf("%d %d", &t, &m);
	vector<pair<int, long double>> v[4];
	for(int i = 0; i < m; i++) {
		char a[2], b[2]; long double c;
		scanf("%s%s%Lf", a, b, &c);
		v[*a - 'A'].emplace_back(*b - 'A', c);
	}
	long double a[4] = {};
	for(int i = 0; i < 4; i++) {
		dfs(v, a, t, 0, i, 0.25);
	}
	for(long double i : a) {
		printf("%Lf\n", i * 100);
	}
}