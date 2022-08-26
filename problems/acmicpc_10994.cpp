#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new char*[n * 4 - 3];
	for(int i = 0; i < (n * 4 - 3); i++) {
		a[i] = new char[n * 4 - 2];
		fill(a[i], a[i] + n * 4 - 3, ' ');
		a[i][n * 4 - 3] = '\0';
	}
	for(int i = 0; i < n; i++) {
		for(int j = -i * 2; j <= i * 2; j++) {
			a[(n - 1) * 2 - i * 2][(n - 1) * 2 + j] = '*';
			a[(n - 1) * 2 + i * 2][(n - 1) * 2 + j] = '*';
			a[(n - 1) * 2 + j][(n - 1) * 2 - i * 2] = '*';
			a[(n - 1) * 2 + j][(n - 1) * 2 + i * 2] = '*';
		}
	}
	char c[2]{ '\0', '\0' };
	for(int i = 0; i < (n * 4 - 3); i++) {
		cout << c << a[i];
		c[0] = '\n';
	}
}