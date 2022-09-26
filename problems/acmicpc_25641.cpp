#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; string s; cin >> s;
	int a[2]{}; for(char c : s) a[c == 't']++;
	reverse(s.begin(), s.end());
	do {
		if(a[0] == a[1]) {
			reverse(s.begin(), s.end());
			cout << s;
			return 0;
		}
		a[s.back() == 't']--;
		s.pop_back();
	} while(!s.empty());
}