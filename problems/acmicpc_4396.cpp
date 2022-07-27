#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string *s[2];
	s[0] = new string[n];
	s[1] = new string[n];
	auto ans = new string[n];
	for(int i = 0; i < n; i++) ans[i].resize(n);
	for(int i = 0; i < n; i++) cin >> s[0][i];
	bool popped = false;
	for(int i = 0; i < n; i++) {
		cin >> s[1][i];
		for(int j = 0; j < n; j++) {
			int cnt = 0;
			if(s[1][i][j] == '.') {
				ans[i][j] = '.';
				continue;
			}
			if(s[0][i][j] == '*') {
				ans[i][j] = '*';
				popped = true;
				continue;
			}
			cnt += (j && s[0][i][j - 1] == '*');
			cnt += (i && s[0][i - 1][j] == '*');
			cnt += (j < n - 1 && s[0][i][j + 1] == '*');
			cnt += (i < n - 1 && s[0][i + 1][j] == '*');
			cnt += (i && j && s[0][i - 1][j - 1] == '*');
			cnt += (i < n - 1 && j && s[0][i + 1][j - 1] == '*');
			cnt += (i && j < n - 1 && s[0][i - 1][j + 1] == '*');
			cnt += (i < n - 1 && j < n - 1 && s[0][i + 1][j + 1] == '*');
			ans[i][j] = (char)('0' + cnt);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(popped && s[0][i][j] == '*') cout << '*';
			else cout << ans[i][j];
		} cout << '\n';
	}
}