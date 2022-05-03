#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ld = long double;
using ll = long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(6);
	cout << fixed;
	int t; cin >> t; while(t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<ld> res;
		for (__int128_t i = -1000000; i <= 1000000; i++) {
			if (((a * i + b) * i + c) * i + d == 0) {
				ll g;
				res.push_back((ld)i);
				b += a * (ll) i;
				c += b * (ll) i;
				d += c * (ll) i;
				assert(!d);
				g = gcd(gcd(a, b), c);
				a /= g; b /= g; c /= g;
				if((a * i + b) * i + c == 0) {
					b += a * (ll) i;
					c += b * (ll) i;
					assert(!c);
					g = gcd(a, b);
					a /= g; b /= g;
					if(abs(a) == 1 && -b / a == i) goto END;
					res.push_back(((ld)-b) / a);
					goto END;
				}
				d = b * b - 4 * a * c;
				if(!d) {
					res.push_back(((ld)-b) / (a << 1));
				}
				else if(d > 0) {
					res.push_back((sqrtl(d) - b) / (a << 1));
					res.push_back(-(sqrtl(d) + b) / (a << 1));
				}
			END:sort(res.begin(), res.end());
				for(ld now : res) {
					cout << now << ' ';
				} cout << '\n';
				break;
			}
		}
	}
}