#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline vector<int> get_primes() {
    vector<int> primes{2, 3};
    vector<bool> visited(1000001);
    int i = 5, d = 4;
    for(; i * i <= 1000000; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j <= 1000000; j += (i << 1)) visited[j] = true;
    } for(; i <= 1000000; i += (d = 6 - d)) if(!visited[i]) primes.push_back(i);
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const primes = get_primes();
    int t;
    for(t = 0; n > 3; t++) {
        for(int p : primes) {
            if(auto it = lower_bound(primes.begin(), primes.end(), n - p); it != primes.end() && *it == n - p) {
                n = n - (p << 1);
                break;
            }
        }
    } cout << t;
}