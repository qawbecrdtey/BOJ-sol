#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		if(s == "anj") { printf("뭐야;"); return 0; }
	}
	printf("뭐야?");
}