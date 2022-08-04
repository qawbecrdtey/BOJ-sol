#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s;
	do {
		getline(cin, s);
		bool bug;
		do {
			bug = false;
			for (int i = 0; i < s.size(); i++) {
				if (i < s.size() - 2 && s[i] == 'B' && s[i + 1] == 'U' && s[i + 2] == 'G') {
					s = s.substr(0, i) + s.substr(i + 3);
					bug = true;
					continue;
				}
			}
		} while(bug);
		cout << s << '\n';
	} while(cin);
}