#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	vector<pair<int, int>> v;
	v.emplace_back(a[n - 1].first, 1);
	for(int i = n - 2; i >= 0; i--) {
		auto it = lower_bound(v.begin(), v.end(), a[i].second, [](pair<int, int> const &a, int b) {
			return a.second >= b;
		});
		if(it == v.end()) {
			v.emplace_back(a[i].first, 1);
			continue;
		}
		it->first = a[i].first;
		it->second++;
	}
	printf("%lu", v.size());
}