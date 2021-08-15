#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt;
	cin >> tt;
	for(int t = 1; t <= tt; t++) {
		cout << "Case #" << t << '\n';
		int n, k;
		cin >> n >> k;
		vector<int> v;
		while(n--) {
			int x; cin >> x;
			if(v.empty() || v.back() < x) {
				v.push_back(x);
				continue;
			}
			*lower_bound(v.begin(), v.end(), x) = x;
		}
		cout << (v.size() >= k) << '\n';
	}
}