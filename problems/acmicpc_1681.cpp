#include <iostream>
#include <string>
using namespace std;
inline string convert(int n) {
	if(n < 9) return { (char)(n + '0') };
	return convert(n / 9) + string{ (char)(n % 9 + '0') };
}
inline bool contains(int n, int k) {
	while(n) {
		if(n % 10 == k) return false;
		n /= 10;
	} return true;
}
int main() {
	int n; char c[2]; cin >> n >> c;
	if(*c != '0') {
		auto s = convert(n);
		for(char &ch : s) {
			if(ch >= *c) ch++;
		}
		cout << s;
		return 0;
	}
	int cnt = 0, cur = 0;
	int const k = *c - '0';
	while(cnt < n) {
		cnt += contains(++cur, k);
	} cout << cur;
}