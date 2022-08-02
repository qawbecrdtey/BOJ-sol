#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	map<int, int> count, appear;
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		count[x]++;
		if(!appear[x]) appear[x] = i + 1;
		a[i] = x;
	} sort(a, a + n, [&count, &appear](int a, int b) {
		return count[a] > count[b] || (count[a] == count[b] && appear[a] < appear[b]);
	});
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
}