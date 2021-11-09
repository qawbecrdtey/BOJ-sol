#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	bool flag = false;
	for(int i = 0; i < s.size() - 1; i++) {
		if((s[i] == 'D' || s[i] == 'd') && s[i + 1] == '2') {
			flag = true;
			break;
		}
	}
	if(flag) printf("D2");
	else printf("unrated");
}