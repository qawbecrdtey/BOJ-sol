#include <iostream>
#include <stack>
using namespace std;
using ull = unsigned long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	stack<ull> s;
	ull sum = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while(!s.empty() && s.top() <= x) {
			s.pop();
			sum += s.size();
		}
		s.push(x);
	}
	while(!s.empty()) {
		s.pop();
		sum += s.size();
	}
	cout << sum;
}