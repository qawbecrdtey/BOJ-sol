#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	auto a = new int[s.size() + 1]();
	a[0] = 1;
	for(int i = 1; i <= s.size(); i++) {
		a[i] += (s[i - 1] != '0') * a[i - 1];
		if(i > 1) a[i] += (s[i - 2] != '0' && stoi(s.substr(i - 2, 2)) < 27) * a[i - 2];
		a[i] %= 1000000;
	} cout << a[s.size()];
}