#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	/*
	2013 F 9
	2012 E 8
	2011 D 7
	2010 C 6
	2009 B 5
	2008 A 4
	2007   3
	2006   2
	2005   1
	2004   0
	*/
	int n; cin >> n;
	cout << (char)('A' + (n % 12 + 12 - 2008 % 12) % 12) << (n % 10 + 10 - 4) % 10;
}