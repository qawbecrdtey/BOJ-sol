#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int a, b; cin >> a >> b;
		string s; cin >> s;
		for(char c : s) {
			cout << (char)(((c - 'A') * a + b) % 26 + 'A');
		} cout << '\n';
	}
}