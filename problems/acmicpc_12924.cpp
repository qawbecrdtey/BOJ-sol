#include <iostream>
#include <set>
#include <string>
using namespace std;
inline int f(int n, int m, int M) {
	string s(to_string(n)); int res = 0;
	set<int> S;
	for(int i = 1; i < s.size(); i++) {
		int const x = stoi(s.substr(i) + s.substr(0, i));
		if(x >= m && x <= M) S.insert(x);
	} for(auto now : S) {
		res += (n < now);
	} return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, res = 0; cin >> a >> b;
	for(int i = a; i < b; i++) {
		res += f(i, a, b);
	} cout << res;
}