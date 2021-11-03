#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b; string c;
	cin >> a >> b >> c;
	if((c.back() - '0') & 1) cout << (a ^ b);
	else cout << a;
}