#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b; string s; while (cin >> a >> s >> b) {
		if (!a && !b && s == "W") return 0;
		if (s == "W") {
			if (a >= b - 200) cout << a - b << '\n';
			else cout << "Not allowed\n";
			continue;
		}
		cout << a + b << '\n';
	}
}