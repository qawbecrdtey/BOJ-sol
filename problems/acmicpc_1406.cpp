#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	stack<char> ls, rs;
	for(auto c : s) ls.push(c);
	int n;
	cin >> n;
	while(n--) {
		cin >> s;
		if(s[0] == 'L') {
			if(!ls.empty()) {
				rs.push(ls.top());
				ls.pop();
			}
		}
		else if(s[0] == 'D') {
			if(!rs.empty()) {
				ls.push(rs.top());
				rs.pop();
			}
		}
		else if(s[0] == 'B') {
			if(!ls.empty()) ls.pop();
		}
		else {
			string b;
			cin >> b;
			ls.push(b[0]);
		}
	}
	while(!ls.empty()) {
		rs.push(ls.top()); ls.pop();
	}
	while(!rs.empty()) {
		cout << rs.top();
		rs.pop();
	}
}