#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string s, t, u; cin >> s >> t; u = s;
	size_t cnts = 0, cntu = 1;
	u[0] = (char)('0' + '1' - u[0]);
	u[1] = (char)('0' + '1' - u[1]);
	for(int i = 1; i < n; i++) {
		if(s[i - 1] != t[i - 1]) {
			s[i - 1] = (char)('0' + '1' - s[i - 1]);
			s[i] = (char)('0' + '1' - s[i]);
			s[i + 1] = (char)('0' + '1' - s[i + 1]);
			cnts++;
		}
		if(u[i - 1] != t[i - 1]) {
			u[i - 1] = (char)('0' + '1' - u[i - 1]);
			u[i] = (char)('0' + '1' - u[i]);
			u[i + 1] = (char)('0' + '1' - u[i + 1]);
			cntu++;
		}
	}
	size_t res = n + 1;
	if(s[n - 1] == t[n - 1]) res = cnts;
	if(u[n - 1] == t[n - 1] && cntu < res) res = cntu;
	if(res == n + 1) cout << -1;
	else cout << res;
}