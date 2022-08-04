#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s, t; getline(cin, s); getline(cin, t);
	int cnt = 0;
	for(int i = 0; i <= (int)s.size() - (int)t.size(); i++) {
		int j;
		for(j = 0; j < t.size(); j++) {
			if(s[i + j] != t[j]) break;
		}
		if(j == t.size()) {
			cnt++;
			i += t.size() - 1;
		}
	}
	cout << cnt;
}