#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
vector<int> primes() {
	auto visited = new bool[10000]();
	vector<int> v;
	int i = 2;
	for(; i <= 100; i++) {
		if(!visited[i]) {
			for(int j = (i << 1); j < 10000; j += i) {
				visited[j] = true;
			}
		}
	}
	for(; i < 10000; i++) {
		if(!visited[i] && i > 1000) v.push_back(i);
	}
	delete[] visited;
	return v;
}
bool adj(int a, int b) {
	int cnt = 0;
	for(int i = 0; i < 4; i++) {
		cnt += (a % 10 == b % 10);
		a /= 10; b /= 10;
	}
	return cnt == 3;
}
int main() {
	int t;
	auto prime = primes();
	auto v = new vector<int>[prime.size()];
	for(int i = 0; i < prime.size(); i++) {
		for(int j = i + 1; j < prime.size(); j++) {
			if(adj(prime[i], prime[j])) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		auto visited = new bool[prime.size()]();
		queue<pair<long, int>> q;
		q.push({ (lower_bound(prime.begin(), prime.end(), x) - prime.begin()), 0 });
		while(!q.empty()) {
			auto const now = q.front(); q.pop();
			if(visited[now.first]) continue;
			visited[now.first] = true;
			if(prime[now.first] == y) {
				printf("%d\n", now.second);
				goto END;
			}
			for(auto next : v[now.first]) {
				if(!visited[next]) q.push({ next, now.second + 1 });
			}
		}
		printf("-1\n");
	END:delete[] visited;
	}
}