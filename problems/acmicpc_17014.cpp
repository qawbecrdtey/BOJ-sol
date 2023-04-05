#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes() {
    vector<int> primes{2, 3};
    vector<bool> visited(2000001);
    int i = 5, d = 4;
    for(; i * i <= 2000000; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j <= 2000000; j += (i << 1)) visited[j] = true;
    }
    for(; i <= 2000000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        for(int p : primes) {
            if(auto it = lower_bound(primes.begin(), primes.end(), 2 * n - p); it != primes.end() && *it == 2 * n - p) {
                cout << p << ' ' << *it << '\n';
                break;
            }
        }
    }
}