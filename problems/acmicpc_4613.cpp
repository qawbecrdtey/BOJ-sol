#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	while(true) {
		getline(cin, s);
		if(s == "#") break;
		long long sum = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') {
				sum += (i + 1) * (s[i] - 'A' + 1);
			}
			else continue;
		}
		cout << sum << '\n';
	}
}