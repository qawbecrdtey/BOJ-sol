#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; auto s = new string[t];
	for(int i = 0; i < t; i++) cin >> s[i];
	auto const l = s[0].size();
	for(int i = l - 1; i >= 0; i--) {
		for(int j = 0; j < t; j++) {
			for(int k = 0; k < j; k++) {
				if(s[j].substr(i) == s[k].substr(i)) goto HI;
			}
		}
		cout << l - i;
		return 0;
	HI:	continue;
	} cout << l;
}