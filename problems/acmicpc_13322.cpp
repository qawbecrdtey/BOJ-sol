#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	for(decltype(s.size()) i = 0; i < s.size(); i++) cout << i << '\n';
}