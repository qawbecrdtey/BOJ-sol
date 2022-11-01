#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m; size_t sz = 0;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		if(sz + s.size() > m) sz = s.size(), cout << '\n' << s;
		else {
			sz += s.size();
			if(i) cout << ' ';
			cout << s;
		}
	}
}