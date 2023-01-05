#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; while(getline(cin, s)) {
		if(s == "#") return 0;
		vector<char> v;
		for(char c : s) {
			switch(c) {
				case '(': v.push_back('('); break;
				case '{': v.push_back('{'); break;
				case '[': v.push_back('['); break;
				case ')': if(v.back() != '(') goto NO; v.pop_back(); break;
				case '}': if(v.back() != '{') goto NO; v.pop_back(); break;
				case ']': if(v.back() != '[') goto NO; v.pop_back(); break;
				default: break;
			}
		} if(!v.empty()) goto NO;
		cout << "Legal\n"; continue;
	NO:	cout << "Illegal\n";
	}
}