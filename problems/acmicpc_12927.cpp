#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	vector<bool> v; v.reserve(s.size() + 1); v.push_back(false);
	for(char c : s) v.push_back(c == 'Y'); int cnt = 0;
	for(decltype(s.size()) i = 1; i <= s.size(); i++) {
		if(v[i]) {
			cnt++;
			for(decltype(i) j = i; j <= s.size(); j += i) {
				v[j] = !v[j];
			}
		}
	} cout << cnt;
}