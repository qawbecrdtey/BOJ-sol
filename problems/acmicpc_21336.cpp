#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check(string const &s, string const &t, int x, int y) {
	bool b[4]{};
	for(int i = 0; i < 4; i++) {
		if(s[i] == t[i]) {
			b[i] = true;
			x--;
		}
	} if(x) return false;
	vector<char> v;
	for(int i = 0; i < 4; i++) {
		if(b[i]) continue;
		v.push_back(s[i]);
	}
	for(int i = 0; i < 4; i++) {
		if(b[i]) continue;
		if(auto it = find(v.begin(), v.end(), t[i]); it != v.end()) {
			y--;
			v.erase(it);
		}
	} return !y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<string> v;
	v.reserve(26 * 26 * 26 * 26);
	for(char a = 'a'; a <= 'z'; a++) {
		for(char b = 'a'; b <= 'z'; b++) {
			for(char c = 'a'; c <= 'z'; c++) {
				for(char d = 'a'; d <= 'z'; d++) {
					v.push_back({{a,b,c,d}});
				}
			}
		}
	}
	string s, t;
	while (true) {
		auto res = v[0];
		cout << res << endl;
		cin >> t; if(t == "correct") return 0;
		int x = stoi(t); int y; cin >> y;
		vector<string> vv;
		for(auto &str : v) {
			if(check(res, str, x, y)) vv.push_back(std::move(str));
		} v = std::move(vv);
	}
}