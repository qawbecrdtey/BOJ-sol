#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<>> pq;
	for(int i = 0; i < n; i++) {
		int x; cin >> x; pq.push(x);
	}
	ll res = 0;
	while(pq.size() != 1) {
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();
		res += x * y; pq.push(x + y);
	} cout << res;
}