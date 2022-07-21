#include <iostream>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; int n; cin >> s >> n;
	set<string> se; se.insert(s);
	int res = 1;
	while(n--) {
		string t, u; cin >> t >> u;
		if(u == s) s = t, se.insert(t);
	} cout << s << '\n' << se.size();
}