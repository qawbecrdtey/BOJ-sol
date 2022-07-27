#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto q = new queue<int>[n];
	for(int i = 0; i < n; i++) {
		int m; cin >> m;
		while(m--) {
			int x; cin >> x; q[i].push(x);
		}
	}
	int selected = 0, idx = 0, score = 0;
	while(selected < k) {
		if(q[idx].empty()) {
			score += 50;
			selected++;
			idx = (idx + 1) % n;
			continue;
		}
		auto const now = q[idx].front(); q[idx].pop();
		if(score > now) {
			idx = (idx + 1) % n;
			continue;
		}
		score += now;
		selected++;
		idx = (idx + 1) % n;
	} cout << score;
}