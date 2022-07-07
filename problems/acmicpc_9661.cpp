#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n; switch(n % 5) {
		case 0:
		case 2: cout << "CY"; break;
		default: cout << "SK"; break;
	} return 0;
}