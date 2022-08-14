#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; int a, b; while(cin >> s >> a >> b) {
		if(s == "#" && !a && !b) return 0;
		cout << s << ' ' << ((a > 17 || b >= 80) ? "Senior\n" : "Junior\n");
	}
}