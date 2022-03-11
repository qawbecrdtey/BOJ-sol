#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline vector<int> get_primes() {
    vector<int> primes = { 2, 3 };
    vector<bool> visited(2000000);
    int i = 5, d = 4;
    for(; i * i <= 2000000; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int j = i; j <= 2000000; j += (i << 1)) {
                visited[j] = true;
            }
        }
    }
    for(; i <= 2000000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
inline bool is_prime(vector<int> const &primes, ll n) {
    if(n < 2000000) {
        return binary_search(primes.begin(), primes.end(), n);
    }
    return all_of(primes.begin(), primes.end(), [&n](int p) -> bool {
        return n % p;
    });
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    int t; cin >> t; while(t--) {
        ll a, b; cin >> a >> b;
        if(a + b == 2) {
            cout << "NO\n";
            continue;
        }
        if(!((a + b) & 1)) {
            cout << "YES\n";
            continue;
        }
        if(is_prime(primes, a + b - 2)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}