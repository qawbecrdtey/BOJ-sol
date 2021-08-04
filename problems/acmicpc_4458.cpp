#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	scanf("%d\n", &n);
	while(n--) {
		string s;
		getline(cin, s);
		if(s[0] >= 'a' && s[0] <= 'z') s[0] += 'A' - 'a';
		cout << s << '\n';
	}
}