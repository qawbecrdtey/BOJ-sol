#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n;
	map<string, int> m;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		m[s]++;
	}
	for(int i = 1; i < n; i++) {
		string s; cin >> s;
		if(!(--m[s])) {
			m.erase(s);
		}
	}
	cout << m.begin()->first;
}