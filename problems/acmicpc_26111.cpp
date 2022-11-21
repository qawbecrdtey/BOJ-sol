#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	long long sum{}, depth = 0;
	for(int i = 1; i < s.size(); i++) {
		if(s[i - 1] == '(' && s[i] == ')') {
			sum += depth;
			depth--;
		}
		else if(s[i] == ')') depth--;
		else if(s[i] == '(') depth++;
	} cout << sum;
}