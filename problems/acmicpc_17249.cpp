#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	bool found = false;
	int res[2]{};
	for(char i : s) {
		if(i == '0') {
			found = true;
			continue;
		}
		if(i == '@') res[found]++;
	} cout << res[0] << ' ' << res[1];
}