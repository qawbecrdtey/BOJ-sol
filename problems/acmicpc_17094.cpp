#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s; cin >> s;
	int res = 0;
	for(auto c : s) res += ((c == 'e') << 1) - 1;
	cout << (!res ? "yee" : (res < 0 ? "2" : "e"));
}