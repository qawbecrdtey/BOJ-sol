#include <iostream>
#include <string>
#include <vector>
using namespace std;
int convert(char c) {
	if(c >= 'A' && c <= 'Z') return c - 'A';
	if(c >= 'a' && c <= 'z') return c - 'a' + 26;
	__builtin_unreachable();
}
char convert(int n) {
	if(n < 26) return (char)(n + 'A');
	if(n < 52) return (char)(n - 26 + 'a');
	__builtin_unreachable();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int d[52][52];
	for(auto &i : d) fill(i, i + 52, 1000000000);
	for(int i = 0; i < 52; i++) d[i][i] = 0;
	while(n--) {
		string a, to, b; cin >> a >> to >> b;
		d[convert(a[0])][convert(b[0])] = 0;
	}
	for(int k = 0; k < 52; k++) {
		for(int i = 0; i < 52; i++) {
			for(int j = 0; j < 52; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	vector<pair<int, int>> res;
	for(int i = 0; i < 52; i++) {
		for(int j = 0; j < 52; j++) {
			if(i != j && !d[i][j]) res.emplace_back(i, j);
		}
	}
	cout << res.size() << '\n';
	for(auto [x, y] : res) {
		cout << convert(x) << " => " << convert(y) << '\n';
	}
}