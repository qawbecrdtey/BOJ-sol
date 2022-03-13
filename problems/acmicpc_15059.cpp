#include <iostream>
using namespace std;
int main() {
	int a[3], b[3];
	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i;
	int res = 0;
	for(int i = 0; i < 3; i++) {
		if(a[i] < b[i]) res += b[i] - a[i];
	} cout << res;
}