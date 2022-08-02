#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> v {
		{1},
		{4, 5},
		{},
		{4, 5},
		{2, 3},
		{8},
		{2, 3},
		{8},
		{6, 7}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; int t = 0; while(cin >> s) {
		if(s == "0") return 0;
		cout << ++t << ". ";
		int cur = 0;
		for(char c : s) {
			if(find(v[cur].begin(), v[cur].end(), c - '0') == v[cur].end()) {
				goto NO;
			}
			else {
				cur = c - '0';
			}
		}
		if(cur != 2) goto NO;
		cout << "VALID\n";
		continue;
	NO:	cout << "NOT\n";
	}
}