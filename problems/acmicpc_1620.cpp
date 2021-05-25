#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	map<int, string> mp1;
	map<string, int> mp2;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mp1[i] = s;
		mp2[s] = i;
	}
	for(int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if(s[0] >= '1' && s[0] <= '9') {
			int x = 0;
			for(char j : s) {
				x *= 10;
				x += j - '0';
			}
			cout << mp1[x] << '\n';
			continue;
		}
		cout << mp2[s] << '\n';
	}
}