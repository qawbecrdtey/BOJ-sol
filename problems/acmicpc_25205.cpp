#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	char c = s.back();
	cout << (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 't' || c == 'a' || c == 's' || c == 'd' || c == 'f' || c == 'g' || c == 'z' || c == 'x' || c == 'c' || c == 'v');
}