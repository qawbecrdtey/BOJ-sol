#include <iostream>
#include <set>
#include <string>
using namespace std;
int count(string const &s) {
	set<char> st;
	for(char c : s) {
		if(c >= 'A' && c <= 'Z') st.insert(c);
	} return (int)st.size();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; getline(cin, s);
	int t = stoi(s); for(int tt = 1; tt <= t; tt++) {
		getline(cin, s);
		int n = stoi(s);
		cout << "Case #" << tt << ": ";
		int m = 0; string r;
		for(int i = 0; i < n; i++) {
			getline(cin, s);
			int const c = count(s);
			if(m < c || (m == c && s < r)) {
				m = c;
				r = s;
			}
		}
		cout << r << '\n';
	}
}