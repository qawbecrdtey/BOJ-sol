#include <iostream>
#include <string>
using namespace std;

int cnt;

int recursion(string const &s, int l, int r){
	cnt++;
	if(l >= r) return 1;
	else if(s[l] != s[r]) return 0;
	else return recursion(s, l+1, r-1);
}

int isPalindrome(string const &s){
	return recursion(s, 0, s.size() - 1);
}

int main(){
	int n; cin >> n;
	while(n--) {
		cnt = 0;
		string s; cin >> s;
		cout << isPalindrome(s) << ' ' << cnt << '\n';
	}
	//printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
	//printf("ABC: %d\n", isPalindrome("ABC"));   // 0
}