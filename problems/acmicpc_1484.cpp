#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int g; cin >> g;
	long long l = 1, r = 1;
	bool flag = false;
	while(l <= 1000000) {
		if(l == r) {
			r++;
		}
		else if(r == 10001) {
			l++;
		}
		else if(r * r - l * l > g) {
			l++;
			continue;
		}
		else if(r * r - l * l < g) {
			r++;
			continue;
		}
		if(r * r - l * l == g) {
			cout << r << '\n';
			r++;
			flag = true;
		}
	}
	if(!flag) {
		cout << -1;
	}
}