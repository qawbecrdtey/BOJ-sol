#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b; cin >> a >> b;
	string s;
	while(a || b) {
		int x = a % 10, y = b % 10;
		if((x < 3 && y < 3) || (x > 6 && y > 6)) s = "0" + s;
		else s = "9" + s;
		a /= 10; b /= 10;
	} if(s.empty()) s = "0"; cout << s;
}