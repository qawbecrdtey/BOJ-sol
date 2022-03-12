#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while(true) {
		string s;
		getline(cin, s);
		if(s == "#") return 0;
		ssize_t start = 0;
		while(true) {
			ssize_t i;
			for(i = start; i < s.size() && s[i] != ' '; i++);
			if(start) cout << ' ';
			if(i == start) break;
			for(ssize_t j = i - 1; j >= start; j--) cout << s[j];
			start = i + 1;
		} cout << '\n';
	}
}