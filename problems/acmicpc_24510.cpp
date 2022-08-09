#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t, m = 0; cin >> t; while(t--) {
		string s; cin >> s;
		int cnt = 0;
		for(int i = 0; i < s.size(); i++) {
			cnt += (i < s.size() - 2 && s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'r');
			cnt += (i < s.size() - 4 && s[i] == 'w' && s[i + 1] == 'h' && s[i + 2] == 'i' && s[i + 3] == 'l' && s[i + 4] == 'e');
		} m = max(cnt, m);
	} cout << m;
}