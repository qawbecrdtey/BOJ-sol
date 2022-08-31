#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;
inline int ccw(pair<ll, ll> const &a, pair<ll, ll> const &b, pair<ll, ll> const &c) {
	ll x = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
	if(x > 0) return 1;
	if(!x) return 0;
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new pair<ll, ll>[n];
	int mini = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		if(a[mini] > a[i]) mini = i;
	} swap(a[mini], a[0]);
	for(int i = 1; i < n; i++) {
		a[i].first -= a[0].first;
		a[i].second -= a[0].second;
	} a[0].first = a[0].second = 0;
	sort(a + 1, a + n, [](pair<ll, ll> const &a, pair<ll, ll> const &b)->bool {
		return a.second * b.first < b.second * a.first || (a.second * b.first == b.second * a.first && (a.first < b.first || (a.first == b.first && a.second < b.second)));
	});
	stack<int> s;
	s.push(0); s.push(1);
	for(int i = 2; i < n; i++) {
		while(s.size() > 1) {
			int second = s.top(); s.pop();
			int first = s.top();
			if(ccw(a[first], a[second], a[i]) == 1) {
				s.push(second);
				break;
			}
		}
		s.push(i);
	}
	cout << s.size() << '\n';
}