#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes(int n) {
    vector<int> primes {2, 3};
    vector<bool> visited(n + 1);
    int i = 5, d = 4;
    for(; i * i <= n; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j < n; j += (i << 1)) visited[j] = true;
    }
    for(; i <= n; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes(1000000);
    int n, k; cin >> n >> k;
    auto a = new int[k]();
    for(auto const p : primes) {
        a[p % k]++;
    }
    for(int i = 0; i < k; i++) {
        if(a[i] >= n) {
            int cnt = 0;
            for(auto const p : primes) {
                if(cnt >= n) break;
                if(p % k != i) continue;
                cout << p << ' ';
                cnt++;
            }
            return 0;
        }
    }
}
