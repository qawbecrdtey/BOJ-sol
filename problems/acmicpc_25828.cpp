#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int g, p, t; cin >> g >> p >> t;
	int const one = g + p * t;
	int const two = g * p;
	if(one > two) cout << 1;
	else if(one < two) cout << 2;
	else cout << 0;
}