#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	string r[5];
	for(char c : s) {
		r[0] += "***";
		switch(c) {
			case 'A':
			case 'B':
			case 'D': r[1] += "*.*"; break;
			case 'C':
			case 'E': r[1] += "*.."; break;
			default: __builtin_unreachable();
		}
		switch(c) {
			case 'A':
			case 'B':
			case 'E': r[2] += "***"; break;
			case 'C': r[2] += "*.."; break;
			case 'D': r[2] += "*.*"; break;
			default: __builtin_unreachable();
		}
		switch(c) {
			case 'A':
			case 'B':
			case 'D': r[3] += "*.*"; break;
			case 'C':
			case 'E': r[3] += "*.."; break;
			default: __builtin_unreachable();
		}
		switch(c) {
			case 'A': r[4] += "*.*"; break;
			case 'B':
			case 'C':
			case 'D':
			case 'E': r[4] += "***"; break;
			default: __builtin_unreachable();
		}
	}
	cout << r[0] << '\n' << r[1] << '\n' << r[2] << '\n' << r[3] << '\n' << r[4];
}