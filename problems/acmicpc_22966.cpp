#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, x, res = 0; cin >> n;
	string s, ress;
	while(n--) {
		cin >> s >> x;
		if(!res || res > x) res = x, ress = s;
	} cout << ress;
}