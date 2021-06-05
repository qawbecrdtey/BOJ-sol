#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long power(int x) {
	if(x == 0) return 1;
	if(x == 1) return 10;
	auto r = power(x / 2);
	return r * r * power(x % 2);
}
int main() {
	int n;
	cin >> n;
	long long a[26] = {};
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++) {
			a[s[j] - 'A'] += power((int)s.size() - j - 1);
		}
	}
	sort(a, a + 26);
	long long res = 0;
	for(long long i = 0; i < 10; i++) {
		res += i * a[i + 16];
	}
	cout << res;
}