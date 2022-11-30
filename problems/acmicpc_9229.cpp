#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool match(string const &s, string const &t) {
	if(s.size() != t.size()) return false;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		cnt += (s[i] != t[i]);
	}
	return cnt == 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(cin >> s) {
		if(s == "#") break;
		vector<string> v{s};
		string t; while(cin >> t) {
			if(t == "#") break;
			v.push_back(std::move(t));
		}
		for(int i = 1; i < v.size(); i++) {
			if(!match(v[i - 1], v[i])) goto NO;
		}
		cout << "Correct\n";
		continue;
	NO:	cout << "Incorrect\n";
	}
}