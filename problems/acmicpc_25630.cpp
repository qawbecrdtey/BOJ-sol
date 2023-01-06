#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s; int sum{};
	for(int i = 0; i < n / 2; i++) {
		sum += (s[i] != s[n - i - 1]);
	} cout << sum;
}