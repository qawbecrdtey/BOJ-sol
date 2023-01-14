#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	map<string, ll> m;
	m["Franklin"] = 100;
	m["Grant"] = 50;
	m["Jackson"] = 20;
	m["Hamilton"] = 10;
	m["Lincoln"] = 5;
	m["Washington"] = 1;
	string s; getline(cin, s); int t = stoi(s); while(t--) {
		getline(cin, s);
		stringstream ss(s);
		string st; ll res = 0; while(ss >> st) res += m[st];
		cout << '$' << res << '\n';
	}
}