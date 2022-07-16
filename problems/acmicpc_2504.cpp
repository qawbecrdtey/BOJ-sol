#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct info {
	char start;
	stack<int> st;
};
inline char convert(char c) {
	switch(c) {
		case ')': return '(';
		case ']': return '[';
		default: __builtin_unreachable();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	stack<info> st; st.push({ '\0', {} });
	for(char c : s) {
		switch(c) {
			case '(':
			case '[': st.push(info{ c, {} }); break;
			case ')':
			case ']': {
				if(st.size() < 2 || st.top().start != convert(c)) {
					cout << 0;
					return 0;
				}
				int res = 0;
				while(!st.top().st.empty()) {
					res += st.top().st.top();
					st.top().st.pop();
				}
				if(!res) res = 2 + (c == ']');
				else res *= 2 + (c == ']');
				st.pop();
				st.top().st.push(res);
			} break;
			default: __builtin_unreachable();
		}
	}
	if(st.size() != 1) {
		cout << 0;
		return 0;
	}
	int res = 0;
	while(!st.top().st.empty()) {
		res += st.top().st.top();
		st.top().st.pop();
	} cout << res;
}