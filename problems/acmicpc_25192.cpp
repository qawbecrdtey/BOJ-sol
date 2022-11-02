#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	set<string> st; int res = 0;
	int t; cin >> t; while(t--) {
		string s; cin >> s;
		if(s == "ENTER") {
			st.clear();
			continue;
		}
		auto p = st.insert(s);
		res += p.second;
	} cout << res;
}