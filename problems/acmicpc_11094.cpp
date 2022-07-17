#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; string s; getline(cin, s); while(n--) {
		getline(cin, s);
		if(s.substr(0, 10) == "Simon says") cout << s.substr(10) << '\n';
	}
}