#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<int> color(n + 1);
	color[1] = 1;
	int cur = 2;
	for(int i = 2; i <= n; i++) {
		if(color[i]) continue;
		for(int j = i; j <= n; j += i) color[j] = cur;
		cur++;
	}
	cout << cur - 1 << '\n';
	for(int i = 1; i <= n; i++) cout << color[i] << ' ';
}