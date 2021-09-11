#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	map<string, string> mp;
	while(n--) {
		string x, y;
		cin >> x >> y;
		mp[x] = y;
	}
	while(m--) {
		string x; cin >> x;
		cout << mp[x] << '\n';
	}
}