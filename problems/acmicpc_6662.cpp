#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;
inline vector<ll> get_primes() {
    vector<ll> primes = { 2, 3 };
    vector<bool> visited(432);
    ll i = 5, d = 4;
    for(; i < 21; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(ll j = i; j < 432; j += (i << 1)) visited[j] = true;
        }
    }
    for(; i < 432; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    auto cnt = new ll[primes.size()];
    ll a, b; while(cin >> a >> b) {
        fill(cnt, cnt + primes.size(), 0);
        if(b > a - b) b = a - b;
        for(ll i = a - b + 1; i <= a; i++) {
            ll tmp = i;
            for(ll j = 0; j < primes.size(); j++) {
                if(tmp == 1) break;
                if(tmp < primes[j] * primes[j]) {
                    cnt[lower_bound(primes.begin(), primes.end(), tmp) - primes.begin()]++;
                    break;
                }
                while(tmp % primes[j] == 0) tmp /= primes[j], cnt[j]++;
            }
        }
        for(ll i = 1; i <= b; i++) {
            ll tmp = i;
            for(ll j = 0; j < primes.size(); j++) {
                if(tmp == 1) break;
                if(tmp < primes[j] * primes[j]) {
                    cnt[lower_bound(primes.begin(), primes.end(), tmp) - primes.begin()]--;
                    break;
                }
                while(tmp % primes[j] == 0) tmp /= primes[j], cnt[j]--;
            }
        }
        ll res = 1;
        for(ll i = 0; i < primes.size(); i++) {
            res *= cnt[i] + 1;
        } cout << res << '\n';
    }
    delete[] cnt;
}