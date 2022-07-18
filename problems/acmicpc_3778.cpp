#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string t; getline(cin, t);
	int tt = stoi(t); for(int ttt = 1; ttt <= tt; ttt++) {
		string s; getline(cin, s); getline(cin, t);
		int a[26]{}; int res = 0;
		for(char c : s) a[c - 'a']++;
		for(char c : t) a[c - 'a']--;
		for(int i : a) res += abs(i);
		cout << "Case #" << ttt << ": " << res << '\n';
	}
}