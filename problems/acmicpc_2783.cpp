#include <iostream>
using namespace std;
int main() {
	int x, y; cin >> x >> y;
	double res = (double)x / y;
	int n; cin >> n;
	while(n--) {
		cin >> x >> y;
		double a = (double)x / y;
		if(a < res) res = a;
	} printf("%.2f", res * 1000);
}