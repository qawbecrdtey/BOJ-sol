#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool comp(string const &a, string const &b) {
	for(int i = 0; i < a.size() && i < b.size(); i++) {
		if(a[i] < b[i]) return true;
		if(a[i] > b[i]) return false;
	}
	if(a.size() > b.size()) {
		for (int i = 0; i < a.size() - b.size(); i++) {
			if(a[i + b.size()] < a[i]) return true;
			if(a[i + b.size()] > a[i]) return false;
		}
	}
	if(b.size() > a.size()) {
		for(int i = 0; i < b.size() - a.size(); i++) {
			if(b[i + a.size()] < b[i]) return false;
			if(b[i + a.size()] > b[i]) return true;
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	auto a = new string[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, comp);
	if(a[n - 1] == "0") {
		cout << 0;
		delete[] a;
		return 0;
	}
	for(int i = n - 1; i >= 0; i--) {
		cout << a[i];
	}
	delete[] a;
}