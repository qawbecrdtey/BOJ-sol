#include <iostream>
#include <string>
using namespace std;
int main() {
	char c;
	string s;
	int res = 0;
	while(cin >> c) {
		if(c != ',' && !(c >= '0' && c <= '9')) continue;
		if(c != ',') {
			s.push_back(c);
			continue;
		}
		res += stoi(s);
		s.clear();
	}
	res += stoi(s);
	cout << res;
}