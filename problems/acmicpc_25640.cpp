#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int n; cin >> n; int res{};
	while(n--) {
		string t; cin >> t; res += (t == s);
	} cout << res;
}