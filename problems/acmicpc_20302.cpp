#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_primes() {
	vector<ll> primes{2, 3};
	vector<bool> visited(100001);
	ll i = 5, d = 4;
	for(; i * i < 100001; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(ll j = i; j <= 100001; j += (i << 1)) visited[j] = true;
		}
	}
	for(; i < 100001; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	}
	return primes;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto const primes = get_primes();
	ll n, x; cin >> n >> x;
	auto a = new ll[primes.size()]();
	if(x == 0) {
		cout << "mint chocolate";
		return 0;
	}
	for(int i = 0; i < primes.size(); i++) {
		if(x == 1) break;
		if(primes[i] * primes[i] > x) {
			a[lower_bound(primes.begin(), primes.end(), x) - primes.begin()]++;
			break;
		}
		while(x % primes[i] == 0) x /= primes[i], a[i]++;
	}
	for(int i = 1; i < n; i++) {
		char c[2]; cin >> c >> x;
		x = abs(x);
		if(*c == '*') {
			if(x == 0) {
				cout << "mint chocolate";
				return 0;
			}
			for(int j = 0; j < primes.size(); j++) {
				if(x == 1) break;
				if(primes[j] * primes[j] > x) {
					a[lower_bound(primes.begin(), primes.end(), x) - primes.begin()]++;
					break;
				}
				while(x % primes[j] == 0) x /= primes[j], a[j]++;
			}
		}
		else {
			for(int j = 0; j < primes.size(); j++) {
				if(x == 1) break;
				if(primes[j] * primes[j] > x) {
					a[lower_bound(primes.begin(), primes.end(), x) - primes.begin()]--;
					break;
				}
				while(x % primes[j] == 0) x /= primes[j], a[j]--;
			}
		}
	}
	for(int i = 0; i < primes.size(); i++) {
		if(a[i] < 0) {
			printf("toothpaste");
			return 0;
		}
	} printf("mint chocolate");
}