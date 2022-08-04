#include <iostream>
#include <string>
using namespace std;
char convert(char a, char b) {
	switch(a) {
		case 'A': {
			switch(b) {
				case 'A':
				case 'C': return 'A';
				case 'G': return 'C';
				case 'T': return 'G';
				default: __builtin_unreachable();
			}
		}
		case 'C': {
			switch(b) {
				case 'A': return 'A';
				case 'C': return 'C';
				case 'G': return 'T';
				case 'T': return 'G';
				default: __builtin_unreachable();
			}
		}
		case 'G': {
			switch(b) {
				case 'A': return 'C';
				case 'C': return 'T';
				case 'G': return 'G';
				case 'T': return 'A';
				default: __builtin_unreachable();
			}
		}
		case 'T': {
			switch(b) {
				case 'A':
				case 'C': return 'G';
				case 'G': return 'A';
				case 'T': return 'T';
				default: __builtin_unreachable();
			}
		}
		default: __builtin_unreachable();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	while(s.size() > 1) {
		char b = s.back(); s.pop_back();
		char a = s.back(); s.pop_back();
		s.push_back(convert(a, b));
	} cout << s;
}