#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	char start; cin >> start;
	string const s("ILOVEYONSEI");
	int res = 0;
	for(char c : s) {
		res += abs(start - c);
		start = c;
	} cout << res;
}