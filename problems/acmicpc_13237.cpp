#include <iostream>
#include <vector>
using namespace std;
void f(int *dist, vector<int> const *v, int now, int d) {
	dist[now] = d;
	for(auto next : v[now]) {
		f(dist, v, next, d + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int root = 0;
	auto v = new vector<int>[n + 1];
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		if(x != -1) v[x].push_back(i);
		else root = i;
	}
	auto dist = new int[n + 1];
	f(dist, v, root, 0);
	for(int i = 1; i <= n; i++) {
		cout << dist[i] << '\n';
	}
}