#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int res = 0;
	for(auto &c : s) {
		if(c > '4') c--;
		res *= 9;
		res += (c - '0');
	}
	printf("%d", res);
}