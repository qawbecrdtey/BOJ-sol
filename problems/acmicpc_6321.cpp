#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		cout << "String #" << i << '\n';
		for(auto c : s) {
			cout << (char)((c - 'A' + 1) % 26 + 'A');
		} cout << "\n\n";
	}
}