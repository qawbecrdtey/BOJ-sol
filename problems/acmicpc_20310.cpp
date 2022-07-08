#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int zeros = 0, ones = 0;
	for(char c : s) zeros += (c == '0'), ones += (c == '1');
	zeros >>= 1, ones >>= 1;
	for(char c : s) {
		if(c == '0' && zeros) {
			cout << c;
			zeros--;
		}
		if(c == '1') {
			if(ones) ones--;
			else cout << c;
		}
	}
}