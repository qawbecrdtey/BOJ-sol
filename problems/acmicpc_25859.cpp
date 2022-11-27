#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int a[26]{};
	for(char c : s) a[c - 'a']++;
	sort(s.begin(), s.end(), [a](char x, char y) { return a[x - 'a'] > a[y - 'a'] || (a[x - 'a'] == a[y - 'a'] && x < y); });
	cout << s;
}