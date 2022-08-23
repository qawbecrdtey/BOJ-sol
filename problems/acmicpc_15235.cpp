#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n];
	auto fixed = new bool[n]();
	fill(a, a + n, 1);
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		q.push({i, x});
	}
	while(!q.empty()) {
		auto [now, cnt] = q.front(); q.pop();
		if(!--cnt) fixed[now] = true;
		else q.push({now, cnt});
		for(int i = 0; i < n; i++) {
			a[i] += (!fixed[i]);
		}
	}
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
}