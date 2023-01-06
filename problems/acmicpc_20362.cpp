#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	map<string, int> m;
	while(n--) {
		string t, u; cin >> t >> u;
		if(t == s) {
			cout << m[u];
			return 0;
		} m[u]++;
	}
}