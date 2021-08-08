#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	while(cin >> s) {
		if(s == "0") return 0;
		int sum = 0;
		for(auto c : s) {
			sum += c - '0';
		}
		while(sum > 9) {
			int x = 0;
			while(sum) {
				x += sum % 10;
				sum /= 10;
			}
			sum = x;
		}
		printf("%d\n", sum);
	}
}