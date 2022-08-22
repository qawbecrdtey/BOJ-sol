#include <iostream>
#include <string>
using namespace std;
constexpr int M = 1000000000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto d = new int*[n];
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		d[i] = new int[n];
		for(int j = 0; j < n; j++) {
			d[i][j] = 1 + M * (s[j] == 'N');
		} d[i][i] = 1;
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int res = 0;
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		for(int j = 0; j < n; j++) {
			cnt += (d[i][j] <= 2);
		} res = max(res, cnt);
	} cout << res - 1;
}