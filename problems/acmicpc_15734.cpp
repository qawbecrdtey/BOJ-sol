#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c; cin >> a >> b >> c;
	while(c) {
		if(a < b) a++, c--;
		else b++, c--;
	} cout << min(a, b) * 2;
}