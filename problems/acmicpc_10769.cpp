#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; getline(cin, s);
	int happy = 0, sad = 0;
	for(int i = 0; i < s.size() - 2; i++) {
		if (s[i] == ':' && s[i + 1] == '-') {
			happy += (s[i + 2] == ')');
			sad += (s[i + 2] == '(');
		}
	}
	if(!happy && !sad) cout << "none";
	else if(happy == sad) cout << "unsure";
	else if(happy < sad) cout << "sad";
	else cout << "happy";
}