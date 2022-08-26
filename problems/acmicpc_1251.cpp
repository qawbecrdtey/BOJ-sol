#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	string res;
	for(int i = 2; i < s.size(); i++) {
		for(int j = 1; j < i; j++) {
			string t(s);
			reverse(t.begin(), t.begin() + j);
			reverse(t.begin() + j, t.begin() + i);
			reverse(t.begin() + i, t.end());
			if(res.empty() || res > t) res = t;
		}
	} cout << res;
}