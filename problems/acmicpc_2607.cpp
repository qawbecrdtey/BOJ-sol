#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s; cin >> s;
	int a[26] = {};
	for(char c : s) {
		a[c - 'A']++;
	}
	int cnt = 0;
	while(--n) {
		string t;
		cin >> t;
		int b[26];
		for(int i = 0; i < 26; i++) {
			b[i] = a[i];
		}
		for(char c : t) {
			b[c - 'A']--;
		}
		int pos = 0, neg = 0;
		bool flag = true;
		for(int i : b) {
			if(i != -1 && i != 0 && i != 1) {
				flag = false; break;
			}
			if(i == 1) pos++;
			if(i == -1) neg++;
		}
		if(flag) {
			if((pos == 1 && neg == 1) || (pos == 1 && neg == 0) || (pos == 0 && neg == 1) || (pos == 0 && neg == 0)) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}