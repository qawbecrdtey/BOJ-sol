#include <stdio.h>
#include <vector>
using namespace std;
void f(vector<pair<int, int>> const *v, bool *chk, int **d, int n, int a) {
	if(!chk[a]) return;
	chk[a] = false;
	for(auto const &now : v[a]) {
		f(v, chk, d, n, now.first);
		for(int i = 1; i <= n; i++) {
			d[a][i] += d[now.first][i] * now.second;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto v = new vector<pair<int, int>>[n + 1];
	auto chk = new bool[n + 1]();
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(b, c);
		chk[a] = true;
	}
	auto d = new int*[n + 1];
	for(int i = 1; i <= n; i++) {
		d[i] = new int[n + 1]();
		if(!chk[i]) {
			d[i][i] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(chk[i]) f(v, chk, d, n, i);
	}
	for(int i = 1; i <= n; i++) {
		if(d[n][i]) {
			printf("%d %d\n", i, d[n][i]);
		}
	}
	delete[] d;
	delete[] chk;
	delete[] v;
}