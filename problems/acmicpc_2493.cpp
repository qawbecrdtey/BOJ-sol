#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	stack<pair<int, int>> s;
	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		while(!s.empty() && s.top().second < x) s.pop();
		if(s.empty()) cout << "0 ";
		else cout << s.top().first << ' ';
		s.push({ i, x });
	}
}