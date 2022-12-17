#include <iostream>
#include <string>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
inline int convert(char c) {
	switch(c) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		default: __builtin_unreachable();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; string s; cin >> n >> s;
	ll a[4]{}; for(char const c : s) a[convert(c)]++;
	cout << (((a[0] * a[1]) % M) * ((a[2] * a[3]) % M)) % M;
}