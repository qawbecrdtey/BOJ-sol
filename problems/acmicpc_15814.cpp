#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s; cin >> s;
	int t; cin >> t; while(t--) {
		int a, b; cin >> a >> b;
		swap(s[a], s[b]);
	} cout << s;
}