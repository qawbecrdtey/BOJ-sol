#include <stdio.h>
#include <vector>
using namespace std;
long long f(long long** a, int n, int min) {
	if(a[min][n] != -1) return a[min][n];
	if(n == 0) return a[min][n] = 1;
	if(min > n) return a[min][n] = 0;
	if(min == n) return a[min][n] = 1;
	long long res = 1;
	for(int i = min; i * 2 <= n; i++) {
		res += f(a, n - i * 2, i);
	}
	return a[min][n] = res;
}
int main() {
	vector<int> input;
	int max = 0;
	while(true) {
		int n;
		scanf("%d", &n);
		if(n == 0) break;
		input.push_back(n);
		if(max < n) max = n;
	}
	auto a = new long long*[max + 1];
	for(int i = 0; i <= max; i++) {
		a[i] = new long long[max + 1]();
		for(int j = 0; j <= max; j++) {
			a[i][j] = -1;
		}
	}
	for(auto n : input) {
		printf("%d %lld\n", n, f(a, n, 1));
	}

	for(int i = 0; i <= max; i++) {
		delete[] a[i];
	}
	delete[] a;
}