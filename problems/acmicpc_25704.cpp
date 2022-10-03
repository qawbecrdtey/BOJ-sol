#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, p; cin >> n >> p;
	int res = 0;
	if(n >= 5) res = max(res, 500);
	if(n >= 10) res = max(res, p / 10);
	if(n >= 15) res = max(res, 2000);
	if(n >= 20) res = max(res, p / 4);
	cout << max(p - res, 0);
}