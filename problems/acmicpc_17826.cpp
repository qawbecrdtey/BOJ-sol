#include <algorithm>
#include <iostream>
using namespace std;
inline char const *score(int n) {
	if(n <= 5) return "A+";
	if(n <= 15) return "A0";
	if(n <= 30) return "B+";
	if(n <= 35) return "B0";
	if(n <= 45) return "C+";
	if(n <= 48) return "C0";
	return "F";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a[50]; for(int &i : a) cin >> i; int x; cin >> x;
	sort(a, a + 50);
	cout << score(50 - (int)(lower_bound(a, a + 50, x) - a));
}