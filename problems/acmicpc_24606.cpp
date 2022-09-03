#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t; cin >> s >> t;
	int res = 1;
	for(int i = 0; i < 4; i++) res <<= (s[i] != t[i]);
	cout << res;
}