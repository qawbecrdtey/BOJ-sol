#include <iostream>
#include <string>
using namespace std;
size_t weight(string const &s) {
	size_t sum{};
	for(char c : s) sum += c - '0';
	return s.size() * sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s, t; cin >> s >> t;
	auto x = weight(s), y = weight(t);
	if(x < y) cout << 2;
	else if(x == y) cout << 0;
	else cout << 1;
}