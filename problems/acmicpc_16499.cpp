#include <array>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	map<array<int, 26>, int> m;
	for(int i = 0; i < n; i++) {
		array<int, 26> arr{};
		string str; cin >> str;
		for(char c : str) arr[c - 'a']++;
		m[arr]++;
	} cout << m.size();
}