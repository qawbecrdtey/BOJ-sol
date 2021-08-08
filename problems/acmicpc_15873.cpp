#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int x, y;
	if(s[0] == '1' && s[1] == '0' && s.size() > 2) x = 10, y = stoi(s.substr(2));
	else x = s[0] - '0', y = stoi(s.substr(1));
	cout << x + y;
}