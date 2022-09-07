#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	string s; cin >> s;
	map<char, int> m;
	for(char c : s) ++m[c];
	if(m.size() < 3) {
		cout << 0;
		return 0;
	}
	auto a = new pair<int, char>[m.size()];
	int i = 0;
	for(auto it = m.begin(); it != m.end(); ++it) {
		a[i++] = { it->second, it->first };
	}
	sort(a, a + m.size());
	if(s.size() < 3) cout << 0;
	else cout << s.size() - a[m.size() - 1].first - a[m.size() - 2].first;
}