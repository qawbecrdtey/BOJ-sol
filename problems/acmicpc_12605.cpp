#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; string s; getline(cin, s); t = stoi(s); for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ":";
		getline(cin, s);
		vector<string> v;
		int start = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == ' ') {
				v.emplace_back(s.substr(start, i - start));
				start = i + 1;
			}
		} v.emplace_back(s.substr(start));
		for(auto it = v.rbegin(); it != v.rend(); ++it) cout << ' ' << *it;
		cout << '\n';
	}
}