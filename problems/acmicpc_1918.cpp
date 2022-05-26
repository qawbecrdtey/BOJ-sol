#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string in, res; cin >> in;
	stack<char> s;
	for(char c : in) {
		switch(c) {
			case '(': s.push(c); break;
			case ')':
				while(s.top() != '(') {
					res += s.top();
					s.pop();
				} s.pop(); break;
			case '*':
			case '/':
				while(!s.empty() && (s.top() == '*' || s.top() == '/')) {
					res += s.top();
					s.pop();
				} s.push(c); break;
			case '+':
			case '-':
				while(!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')) {
					res += s.top();
					s.pop();
				} s.push(c); break;
			default: res += c; break;
		}
	}
	while(!s.empty()) { res += s.top(); s.pop(); }
	cout << res;
}