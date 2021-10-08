#include <iostream>
using namespace std;
using ull = unsigned long long;
int main() {
	ull n, m, res = 1;
	cin >> n >> m;
	int i = 0;
	for(; i < n % m; i++) res *= n / m + 1;
	for(; i < m; i++) res *= n / m;
	cout << res;
}