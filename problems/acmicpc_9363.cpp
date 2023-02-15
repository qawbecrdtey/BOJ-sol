#include <iostream>
#include <map>
#include <vector>
using namespace std;
inline vector<int> get_primes() {
    vector<int> primes{ 2, 3 };
    vector<bool> visited(1001);
    int i = 5, d = 4;
    for(; i * i <= 1000; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j <= 1000; j += (i << 1)) visited[j] = true;
    } for(; i <= 1000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    } return primes;
}
inline int power(int n, int p) {
    int res = 1;
    while(p) {
        if(p & 1) res *= n;
        n *= n; p >>= 1;
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        map<int, int> mp;
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            for(int j = 0; j < primes.size() && primes[j] <= x; j++) {
                while(x % primes[j] == 0) {
                    x /= primes[j];
                    mp[primes[j]]++;
                }
            } if(x != 1) mp[x]++;
        }
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            for(int j = 0; j < primes.size() && primes[j] <= x; j++) {
                while(x % primes[j] == 0) {
                    x /= primes[j];
                    mp[primes[j]]--;
                }
            } if(x != 1) mp[x]--;
        } int num = 1, den = 1;
        for(auto [key, val] : mp) {
            if(val > 0) num *= power(key, val);
            if(val < 0) den *= power(key, -val);
        } cout << num << " / " << den << '\n';
    }
}