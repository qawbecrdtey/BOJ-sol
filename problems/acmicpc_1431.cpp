#include <iostream>
#include <algorithm>
using namespace std;
int sum(string const &s) {
	int res = 0;
	for(auto c : s) {
		if(c >= '0' && c <= '9') res += c - '0';
	}
	return res;
}
bool comp(string const &a, string const &b) {
	if(a.size() < b.size()) return true;
	if(b.size() < a.size()) return false;
	auto const x = sum(a);
	auto const y = sum(b);
	if(x < y) return true;
	if(x > y) return false;
	return a < b;
}
int main() {
	int n;
	cin >> n;
	auto a = new string[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, comp);
	for(int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
	delete[] a;
}