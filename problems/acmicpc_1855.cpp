#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	bool left = true;
	auto a = new string[s.size() / n];
	for(int i = 0; i < s.size(); i += n) {
		int const x = i / n;
		a[x].resize(n);
		if(left) {
			for(int j = 0; j < n; j++) {
				a[x][j] = s[i + j];
			}
		}
		else {
			for(int j = n - 1; j >= 0; j--) {
				a[x][j] = s[i + n - 1 - j];
			}
		}
		left = !left;
	}
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < s.size() / n; i++) {
			cout << a[i][j];
		}
	}
}