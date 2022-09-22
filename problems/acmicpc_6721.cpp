#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string a, b; cin >> a >> b;
		while(!a.empty() && a.back() == '0') a.pop_back();
		while(!b.empty() && b.back() == '0') b.pop_back();
		if(a.empty()) a.push_back('0');
		if(b.empty()) b.push_back('0');
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		string c = std::to_string(stoull(a) + stoull(b));
		while(!c.empty() && c.back() == '0') c.pop_back();
		if(c.empty()) c.push_back('0');
		reverse(c.begin(), c.end());
		cout << c << '\n';
	}
}