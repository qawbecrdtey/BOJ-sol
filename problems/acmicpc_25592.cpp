#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int take = 1; bool turn = true;
	while(take <= n) n -= take++, turn = !turn;
	if(!turn) cout << 0;
	else cout << take - n;
}