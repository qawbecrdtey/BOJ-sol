#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ull = unsigned long long;
string to_string(__int128_t n) {
	string s;
	while(n) {
		s.push_back((char)(n % 10 + '0'));
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
vector<string> f(ull n) {
	vector<string> v;
	__int128_t mul = 1;
	while(n) {
		if(n & 1) {
			v.push_back(to_string(mul));
		}
		n >>= 1;
		mul *= 3;
	}
	return v;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ull n; while(cin >> n) {
		if(!n) return 0;
		auto v = f(n - 1);
		char a[3]{ ' ', '\0', '\0' };
		cout << '{';
		for(auto const &now : v) {
			cout << a << now;
			a[0] = ',', a[1] = ' ';
		} cout << " }\n";
	}
}