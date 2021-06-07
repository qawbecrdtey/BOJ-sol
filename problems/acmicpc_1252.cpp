#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int c = 0;
	stack<int> s;
	int i;
	for(i = 1; i <= a.size() && i <= b.size(); i++) {
		int x = (a[a.size() - i] - '0') + (b[b.size() - i] - '0') + c;
		s.push(x % 2);
		c = x / 2;
	}
	for(; i <= a.size(); i++) {
		int x = (a[a.size() - i] - '0') + c;
		s.push(x % 2);
		c = x / 2;
	}
	for(; i <= b.size(); i++) {
		int x = (b[b.size() - i] - '0') + c;
		s.push(x % 2);
		c = x / 2;
	}
	if(c) s.push(1);
	while(!s.empty() && s.top() == 0) s.pop();
	if(s.empty()) {
		cout << '0';
		return 0;
	}
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
}