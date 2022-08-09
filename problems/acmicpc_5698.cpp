#include <iostream>
#include <string>
using namespace std;
int num(char c) {
	if(c >= 'a' && c <= 'z') return c - 'a';
	if(c >= 'A' && c <= 'Z') return c - 'A';
	__builtin_unreachable();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(getline(cin, s)) {
		if(s == "*") break;
		int idx = 0;
		while(s[idx] == ' ') idx++;
		int const x = num(s[idx++]);
		while(idx < s.size()) {
			if(s[idx - 1] == ' ' && s[idx] != ' ') {
				if(num(s[idx]) != x) goto NO;
			}
			idx++;
		}
		cout << "Y\n";
		continue;
	NO:	cout << "N\n";
	}
}