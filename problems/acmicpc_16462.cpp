#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, sum = 0; cin >> n; for(int i = 0; i < n; i++) {
		string s; cin >> s;
		int x = 0;
		if(s == "0") continue;
		for(char c : s) {
			if(c == '0' || c == '6') c = '9';
			x = x * 10 + c - '0';
		} if(x > 100) x = 100;
		sum += x;
	} cout << sum / n + (sum % n >= (n + 1) / 2);
}