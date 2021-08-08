#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int a[3];
	while(cin >> a[0] >> a[1] >> a[2]) {
		if(a[0] == 0 && a[1] == 0 && a[2] == 0) return 0;
		sort(a, a + 3);
		if(a[2] >= a[0] + a[1]) cout << "Invalid\n";
		else if(a[0] == a[1] && a[1] == a[2]) cout << "Equilateral\n";
		else if(a[0] == a[1] || a[1] == a[2]) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}
}