#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	cout << "int a;";
	for(int i = 1; i <= n; i++) {
		cout << "\nint " << string(i, '*') << "ptr" << (i == 1 ? string() : to_string(i)) << " = &" << (i == 1 ? "a" : "ptr" + (i == 2 ? string() : to_string(i - 1))) << ';';
	}
}