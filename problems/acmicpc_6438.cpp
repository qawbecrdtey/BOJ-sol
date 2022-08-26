#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; getline(cin, s); int t = stoi(s); while(t--) {
		getline(cin, s); for(auto it = s.rbegin(); it != s.rend(); ++it) cout << *it;
		cout << '\n';
	}
}