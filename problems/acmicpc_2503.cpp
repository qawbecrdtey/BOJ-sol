#include <stdio.h>
#include <set>
using namespace std;
bool satisfy(int n) {
	int a[3];
	for(auto &i : a) {
		if(!(i = n % 10)) return false;
		n /= 10;
	}
	return a[0] != a[1] && a[1] != a[2] && a[2] != a[0];
}
int strike(int a, int b) {
	int res = 0;
	for(int i = 0; i < 3; i++) {
		res += (a % 10 == b % 10);
		a /= 10; b /= 10;
	}
	return res;
}
int ball(int a, int b) {
	int x[3], y[3];
	for(auto &i : x) {
		i = a % 10;
		a /= 10;
	}
	for(auto &i : y) {
		i = b % 10;
		b /= 10;
	}
	int res = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(i == j) continue;
			res += (x[i] == y[j]);
		}
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	set<int> s;
	for(int i = 12; i < 1000; i++) {
		if(satisfy(i)) s.insert(i);
	}
	for(int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		for(auto it = s.begin(); it != s.end();) {
			if(strike(a, *it) == b && ball(a, *it) == c) ++it;
			else it = s.erase(it);
		}
	}
	printf("%ld", s.size());
}