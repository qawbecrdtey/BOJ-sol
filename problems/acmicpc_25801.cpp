#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s; map<char, int> m;
	for(char c : s) m[c]++;
	bool odd{}, even{};
	for(auto [now, cnt] : m) {
		if(cnt & 1) odd = true;
		else even = true;
	} if(odd && even) cout << "0/1";
	else if(odd) cout << "1";
	else cout << "0";
}