#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		cout << "Case # " << tt << ":\n";
		string s; cin >> s;
		auto a = new int[s.size()];
		for(int i = 0; i < s.size(); i++) a[i] = i;
		do {
			for(int i = 0; i < s.size(); i++) {
				cout << s[a[i]];
			} cout << '\n';
		} while(next_permutation(a, a + s.size()));
		delete[] a;
	}
}