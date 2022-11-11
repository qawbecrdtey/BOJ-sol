#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s; int x;
	if(s.size() < 3) x = stoi(s);
	else x = stoi(s.substr(s.size() - 2));
	if(s == "0") cout << 1;
	else if(x % 4 == 0) cout << 6;
	else if(x % 4 == 1) cout << 2;
	else if(x % 4 == 2) cout << 4;
	else if(x % 4 == 3) cout << 8;
}