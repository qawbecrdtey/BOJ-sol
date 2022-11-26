#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int right, wrong; string s, t; cin >> right >> s >> t;
	wrong = s.size() - right;
	int res = 0;
	for(int i = 0; i < s.size(); i++) {
		if(right && s[i] == t[i]) {
			res++;
			right--;
		}
		else if(wrong && s[i] != t[i]) {
			res++;
			wrong--;
		}
	} cout << res;
}