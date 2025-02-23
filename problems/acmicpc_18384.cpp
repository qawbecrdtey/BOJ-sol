#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes(int const n) {
    vector<int> primes{2, 3};
    vector<bool> visited(n + 1);
    int i = 5, d = 4;
    for(; i * i <= n; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j <= n; j += (i << 1)) visited[j] = true;
    }
    for(; i <= n; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes(1100000);
    int t; cin >> t; while(t--) {
        int sum = 0;
        for(int i = 0; i < 5; i++) {
            int x; cin >> x;
            if(x <= 2) { sum += 2; continue; }
            sum += *lower_bound(primes.begin(), primes.end(), x);
        }
        cout << sum << '\n';
    }
}
