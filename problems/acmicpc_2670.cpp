#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	auto a = new double[n];
	double max = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i && a[i - 1] > 1) {
			a[i] *= a[i - 1];
		}
		if(max < a[i]) max = a[i];
	}
	cout.precision(3);
	cout << fixed;
	cout << max;
}