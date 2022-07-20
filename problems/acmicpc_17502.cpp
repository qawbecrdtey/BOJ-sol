#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; string s; cin >> s;
	for(int i = 0; i < (n + 1) / 2; i++) {
		if(s[i] == '?') {
			if(s[n - i - 1] == '?') {
				s[n - i - 1] = 'a';
			} s[i] = s[n - i - 1];
		}
		else if(s[n - i - 1] == '?') {
			s[n - i - 1] = s[i];
		}
	} cout << s;
}