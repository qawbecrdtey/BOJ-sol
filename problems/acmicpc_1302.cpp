#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; map<string, int> m;
	while(n--) {
		string s; cin >> s; m[s]++;
	} auto it = m.begin();
	for(auto itt = m.begin(); itt != m.end(); ++itt) {
		if(itt->second > it->second) it = itt;
	} cout << it->first;
}