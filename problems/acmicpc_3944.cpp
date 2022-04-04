#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; string s; cin >> n >> s;
		int sum = 0;
		for(auto c : s) {
			sum = (sum + c - '0') % (n - 1);
		} cout << sum << '\n';
	}
}