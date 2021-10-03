#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	for(int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < s.size() - 2; j++) {
			if(s[j] == 'F' && s[j + 1] == 'B' && s[j + 2] == 'I') {
				v.push_back(i + 1);
				break;
			}
		}
	}
	if(v.empty()) {
		cout << "HE GOT AWAY!";
	}
	else {
		for(auto now : v) cout << now << ' ';
	}
}