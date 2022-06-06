#include <iostream>
#include <set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b; cin >> a >> b;
	set<int> sa;
	for(int i = 0; i < a; i++) {
		int x; cin >> x; sa.insert(x);
	} for(int i = 0; i < b; i++) {
		int x; cin >> x;
		auto p = sa.find(x);
		if(p != sa.end()) sa.erase(p);
	} cout << sa.size() << '\n';
	for(int now : sa) cout << now << ' ';
}