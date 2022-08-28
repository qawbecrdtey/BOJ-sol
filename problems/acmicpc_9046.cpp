#include <array>
#include <iostream>
#include <string>
using namespace std;
inline array<int, 26> cnt(string const &s) {
	array<int, 26> arr{};
	for(char c : s) {
		if(c >= 'a' && c <= 'z') arr[c - 'a']++;
	} return arr;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; getline(cin, s); int t = stoi(s); while(t--) {
		getline(cin, s); auto arr = cnt(s);
		int res = 0; bool flag = false;
		for(int i = 1; i < 26; i++) {
			if(arr[res] < arr[i]) res = i, flag = false;
			else if(arr[res] == arr[i]) flag = true;
		}
		if(flag) cout << "?\n";
		else cout << (char)(res + 'a') << '\n';
	}
}