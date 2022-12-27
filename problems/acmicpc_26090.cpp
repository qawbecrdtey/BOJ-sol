#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_primes() {
    vector<ll> primes{ 2, 3 };
    auto visited = new bool[1000001]{};
    ll i = 5, d = 4;
    for(; i <= 1000; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(ll j = i; j <= 1000000; j += (i << 1)) visited[j] = true;
    }
    for(; i <= 1000000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    delete[] visited;
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    int n; cin >> n; auto a = new int[n + 2]; a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] += a[i - 1];
    } a[n + 1] = a[n];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cnt += (binary_search(primes.begin(), primes.end(), a[j] - a[i]) && binary_search(primes.begin(), primes.end(), j - i));
        }
    } cout << cnt;
}