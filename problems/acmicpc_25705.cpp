#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	set<char> st;
	for(char c : s) st.insert(c);
	int m; string t; cin >> m >> t;
	for(char c : t) {
		if(st.find(c) == st.end()) {
			cout << -1;
			return 0;
		}
	}
	int cur = n - 1, idx = 0, cnt = 0;
	while(idx < t.size()) {
		cur = (cur + 1) % n; cnt++;
		if(s[cur] == t[idx]) idx++;
	} cout << cnt;
}
