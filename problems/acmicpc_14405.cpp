#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int idx = 0;
	while(idx < s.size()) {
		bool flag = false;
		if(idx + 1 < s.size() && s[idx] == 'p' && s[idx + 1] == 'i') flag = true, idx += 2;
		if(idx + 1 < s.size() && s[idx] == 'k' && s[idx + 1] == 'a') flag = true, idx += 2;
		if(idx + 2 < s.size() && s[idx] == 'c' && s[idx + 1] == 'h' && s[idx + 2] == 'u') flag = true, idx += 3;
		if(!flag) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}