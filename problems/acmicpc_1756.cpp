#include <iostream>
#include <deque>
#include <stack>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int d, n;
	cin >> d >> n;
	stack<pair<int, int>> st;
	deque<pair<int, int>> dq;
	for(int i = 1; i <= d; i++) {
		int x;
		cin >> x;
		st.push(make_pair(x, i));
	}
	while(!st.empty()) {
		auto now = st.top(); st.pop();
		while(!dq.empty() && dq.back().first >= now.first) dq.pop_back();
		dq.push_back(move(now));
	}
	int prev;
	while(n--) {
		int x;
		cin >> x;
		while(!dq.empty() && dq.front().second > d) {
			dq.pop_front();
		}
		while(!dq.empty() && dq.front().first < x) {
			d = dq.front().second - 1;
			dq.pop_front();
		}
		if(!d) {
			cout << 0;
			return 0;
		}
		prev = d--;
	}
	cout << prev;
}