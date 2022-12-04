#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int k, n; cin >> k >> n; k--;
	auto a = new int[n];
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = 0; j < i; j++) {
			v.emplace_back(a[j], a[i]);
		}
	} sort(v.begin(), v.end());
	while(k--) {
		vector<pair<int, int>> vv;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			for(int j = 0; j < i; j++) {
				if(binary_search(v.begin(), v.end(), make_pair(a[j], a[i]))) {
					vv.emplace_back(a[j], a[i]);
				}
			}
		}
		v = std::move(vv);
		sort(v.begin(), v.end());
	} cout << v.size();
}