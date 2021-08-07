#include <stdio.h>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	auto a = new pair<int, int>[200001];
	for(int i = 0; i <= 200000; i++) {
		a[i] = { -1, 0 };
	}
	a[n].second = -1;
	queue<pair<pair<int, int>, int>> q; // now, prev, cnt
	q.push({ { n, -1 }, 0 });
	stack<int> s;
	while(!q.empty()) {
		auto const now = q.front(); q.pop();
		if(a[now.first.first].first != -1) continue;
		a[now.first.first].first = now.second;
		a[now.first.first].second = now.first.second;
		if(now.first.first == k) {
			printf("%d\n", now.second);
			int cur = now.first.first;
			while(cur != -1) {
				s.push(cur);
				cur = a[cur].second;
			}
			break;
		}
		if(now.first.first && a[now.first.first - 1].first == -1) {
			q.push({ { now.first.first - 1, now.first.first }, now.second + 1 });
		}
		if(now.first.first < 200000 && a[now.first.first + 1].first == -1) {
			q.push({ { now.first.first + 1, now.first.first }, now.second + 1 });
		}
		if(now.first.first <= 100000 && a[now.first.first * 2].first == -1) {
			q.push({ { now.first.first * 2, now.first.first }, now.second + 1 });
		}
	}
	delete[] a;
	while(!s.empty()) {
		printf("%d ", s.top()); s.pop();
	}
}