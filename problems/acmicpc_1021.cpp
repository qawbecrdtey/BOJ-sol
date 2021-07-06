#include <stdio.h>
#include <deque>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	std::deque<int> dq;
	for(int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	int sum = 0;
	while(m--) {
		int x, cnt = 0;
		scanf("%d", &x);

		while(dq.front() != x) {
			auto const tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
			cnt++;
		}
		if(cnt > dq.size() - cnt) cnt = dq.size() - cnt;
		sum += cnt;
		dq.pop_front();
	}
	printf("%d", sum);
}