#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	while(t.size() > s.size()) {
		bool b = (t.back() == 'B');
		t = t.substr(0, t.size() - 1);
		if(b) {
			for(int i = 0; i < t.size() / 2; i++) {
				auto tmp = t[i];
				t[i] = t[t.size() - 1 - i];
				t[t.size() - 1 - i] = tmp;
			}
		}
	}
	printf("%d", s == t);
}