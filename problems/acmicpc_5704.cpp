#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	bool b[26];
	while(true) {
		getline(cin, s);
		if(s == "*") break;
		fill(b, b + 26, false);
		for(char c : s) {
			if(c >= 'a' && c <= 'z') {
				b[c - 'a'] = true;
			}
		}
		bool flag = false;
		for(auto val : b) {
			if(!val) {
				flag = true;
				printf("N\n");
				break;
			}
		}
		if(!flag) printf("Y\n");
	}
}