#include <iostream>
#include <string>
using namespace std;
void print(int n, int i) {
	cout << string(i, ' ') << '*' << string(n - 2, i ? ' ' : '*') << '*';
	if(i != n - 1) cout << string(2 * (n - i) - 3, ' ') << '*';
	cout << string(n - 2, i ? ' ' : '*') << '*';
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) { print(n, i); cout << '\n'; }
	for(int i = n - 2; i >= 0; i--) { print(n, i); if(i) cout << '\n'; }
}