#include <iostream>
using namespace std;
using ll = long long;
inline bool is_full(bool const visited[10]) {
	for(int i = 0; i < 10; i++) {
		if(!visited[i]) return false;
	} return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; while(cin >> n) {
		int k = 0;
		bool visited[10]{};
		for(ll i = n; !is_full(visited); i += n, k++) {
			ll x = i;
			while(x) {
				visited[x % 10] = true;
				x /= 10;
			}
		} cout << k << '\n';
	}
}