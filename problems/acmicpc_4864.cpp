#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	vector<int> v; int x;
	while(cin >> x) {
		if(x == 0) break;
		v.push_back(x);
	} auto m = *max_element(v.begin(), v.end());
	auto a = new ll[m + 1]; a[0] = 0;
	ll left = 1, cur = 1, sum = 0;
	for(int i = 1; i <= m; i++) {
		sum += cur; a[i] = sum;
		if(!--left) { cur++; left = cur; }
	}
	for(int now : v) {
		cout << now << ' ' << a[now] << '\n';
	}
}