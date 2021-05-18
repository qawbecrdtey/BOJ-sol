#include <iostream>
#include <map>
using namespace std;
int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		map<int, int> m;
		int n;
		cin >> n;
		while(n--) {
			string str;
			cin >> str;
			if(str == "I") {
				int x;
				cin >> x;
				if(m.find(x) != m.end()) {
					m[x]++;
				}
				else m[x] = 1;
			}
			else if(str == "D") {
				int x;
				cin >> x;
				if(m.empty()) continue;
				if(x == 1) {
					if(--m.rbegin()->second == 0) {
						m.erase(m.rbegin()->first);
					}
				}
				else {
					if(--m.begin()->second == 0) {
						m.erase(m.begin()->first);
					}
				}
			}
		}
		if(m.empty()) cout << "EMPTY\n";
		else {
			cout << m.rbegin()->first << ' ' << m.begin()->first << '\n';
		}
	}
}