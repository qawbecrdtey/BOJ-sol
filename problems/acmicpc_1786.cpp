#include <iostream>
#include <string>
#include <vector>
using namespace std;
uint64_t *get_pi(string const &s) {
	auto pi = new uint64_t[s.size()]();
	uint64_t cur = 0;
	for(int i = 1; i < s.size(); i++) {
		while(cur && s[i] != s[cur]) cur = pi[cur - 1];
		if(s[i] == s[cur]) pi[i] = ++cur;
	}
	return pi;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s, t;
	getline(cin, s);
	getline(cin, t);
	vector<uint64_t> res;
	auto pi = get_pi(t);
	uint64_t cur = 0;
	for(uint64_t i = 0; i < s.size(); i++) {
		while(cur && s[i] != t[cur]) cur = pi[cur - 1];
		if(s[i] == t[cur]) {
			if(cur == t.size() - 1) {
				res.push_back(i - t.size() + 1);
				cur = pi[cur];
			}
			else cur++;
		}
	}
	delete[] pi;
	cout << res.size() << '\n';
	for(auto val : res) cout << val + 1 << ' ';
}