#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if(v.empty() || v.back() < a[x - 1].second) {
			v.push_back(a[x - 1].second);
			continue;
		}
		v[lower_bound(v.begin(), v.end(), a[x - 1].second) - v.begin()] = a[x - 1].second;
	}
	cout << v.size();
}