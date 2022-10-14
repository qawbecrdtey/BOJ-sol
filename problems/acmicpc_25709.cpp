#include <iostream>
#include <string>
using namespace std;
using ll = long long;
inline ll erase_one(ll n) {
	if(n == 1) return 0;
	auto s = to_string(n);
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') {
			return stoll(s.substr(0, i) + s.substr(i + 1));
		}
	} return n;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n, tmp, cnt{}; cin >> n;
	while(n) {
		tmp = erase_one(n);
		if(n == tmp) n--; else n = tmp;
		cnt++;
	} cout << cnt;
}