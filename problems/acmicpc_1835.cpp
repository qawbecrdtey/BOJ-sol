#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new int[n + 1]();
	queue<int> q;
	for(int i = 1; i <= n; i++) q.push(i);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			int const x = q.front(); q.pop();
			q.push(x);
		}
		a[q.front()] = i;
		q.pop();
	}
	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
}