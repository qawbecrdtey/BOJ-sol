#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s;
	int cur = 0, sum = 0;
	for(char c : s) {
		int const x = c - 'A';
		sum += min({abs(cur - x), abs(26 + cur - x), abs(x - cur), abs(26 + x - cur)});
		cur = x;
	} cout << sum;
}