#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for(int i = 0; i < 10; i++) {
		cout << "SciComLove"[(n + i) % 10];
	}
}