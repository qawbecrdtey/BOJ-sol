#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s, t; cin >> n >> s;
	for(char c : s) {
		if(c != 'A' && c != 'J' && c != 'V') t += c;
	} if(t.empty()) t = "nojava";
	cout << t;
}