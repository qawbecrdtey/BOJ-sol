#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s; cin >> s;
		int x = 0;
		for(char c : s) x = (x << 1) | (c - '0');
		cout << x << '\n';
	}
}