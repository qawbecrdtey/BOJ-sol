#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(getline(cin, s)) {
		if(s == "END") return 0;
		bool a[26]{}; bool flag{};
		for(char c : s) {
			if(c < 'A' || c > 'Z') continue;
			if(a[c - 'A']) {
				flag = true;
				break;
			} a[c - 'A'] = true;
		} if(!flag) cout << s << '\n';
	}
}