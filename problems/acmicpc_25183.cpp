#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	for(int i = 0; i < s.size() - 4; i++) {
		if(abs(s[i] - s[i + 1]) == 1 && abs(s[i + 1] - s[i + 2]) == 1 && abs(s[i + 2] - s[i + 3]) == 1 && abs(s[i + 3] - s[i + 4]) == 1) {
			cout << "YES";
			return 0;
		}
	} cout << "NO";
}