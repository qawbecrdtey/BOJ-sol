#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	scanf("%d\n", &n);
	while(n--) {
		string s;
		getline(cin, s);
		int g = 0, b = 0;
		for(auto c : s) {
			if(c == 'g' || c == 'G') g++;
			if(c == 'b' || c == 'B') b++;
		}
		cout << s << " is ";
		if(g == b) cout << "NEUTRAL\n";
		else if(g > b) cout << "GOOD\n";
		else cout << "A BADDY\n";
	}
}