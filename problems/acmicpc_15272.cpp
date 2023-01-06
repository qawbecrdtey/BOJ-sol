#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s; for(int i = 1; i < s.size(); i++) {
		if(s[i - 1] == s[i] && s[i] == 's') goto END;
	}
	cout << "no ";
END: cout << "hiss";
}