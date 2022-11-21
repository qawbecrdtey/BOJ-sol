#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	int a[5]{};
	for(char c : s) {
		a[0] += (c == 'H');
		a[1] += (c == 'I');
		a[2] += (c == 'A');
		a[3] += (c == 'R');
		a[4] += (c == 'C');
	} cout << *min_element(a, a + 5);
}