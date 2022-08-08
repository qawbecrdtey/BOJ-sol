#include <cstdio>
#include <deque>
int main() {
	int n; scanf("%d", &n);
	std::deque<std::pair<int, int>> dq;
	for(int i = 0; i < n; i++) {
		int x; scanf("%d", &x); dq.push_back({x, i});
	}
	for(int i = 0; i < n; i++) {
		auto [x, idx] = dq.front(); dq.pop_front();
		printf("%d ", idx + 1);
		if(dq.empty()) break;
		if(x > 0) {
			for(int j = 1; j < x; j++) {
				auto y = std::move(dq.front());
				dq.pop_front();
				dq.push_back(std::move(y));
			}
		}
		else {
			x = -x;
			for(int j = 0; j < x; j++) {
				auto y = std::move(dq.back());
				dq.pop_back();
				dq.push_front(std::move(y));
			}
		}
	}
}