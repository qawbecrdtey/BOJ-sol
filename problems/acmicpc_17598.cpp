#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s;
	int tiger = 0;
	for(int i = 0; i < 9; i++) {
		cin >> s;
		tiger += (s == "Tiger");
	} cout << (tiger < 5 ? "Lion" : "Tiger");
}