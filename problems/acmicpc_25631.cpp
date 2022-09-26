#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
struct info {
	int x, vacant;
	bool operator<(info const &i) const {
		return x < i.x;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; s.insert(x);
	}
	int pile = 0;
	while(!s.empty()) {
		int len = 1;
		auto cur_it = s.begin();
		for(auto it = next(cur_it); it != s.end(); ++it) {
			if(*cur_it < *it) {
				s.erase(cur_it);
				cur_it = it;
				len++;
			}
		}
		if(len == 1) break;
		pile++; s.erase(cur_it);
	} cout << s.size() + pile;
}