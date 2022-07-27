#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int x, y; cin >> x >> y;
	int z = y - x;
	cout << (y + z - 1) / z;
}