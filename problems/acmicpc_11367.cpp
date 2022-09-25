#include <iostream>
#include <string>
using namespace std;
char const *f(int n) {
	if(n < 60) return "F";
	if(n < 67) return "D";
	if(n < 70) return "D+";
	if(n < 77) return "C";
	if(n < 80) return "C+";
	if(n < 87) return "B";
	if(n < 90) return "B+";
	if(n < 97) return "A";
	return "A+";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s; int n; cin >> s >> n;
		cout << s << ' ' << f(n) << '\n';
	}
}