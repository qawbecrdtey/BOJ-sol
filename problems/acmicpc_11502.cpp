#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes() {
    vector<int> primes{ 2, 3 };
    vector<bool> visited(1000);
    int i = 5, d = 4;
    for(; i * i <= 1000; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int j = i; j <= 1000; j += (i << 1)) visited[j] = true;
        }
    }
    for(; i <= 1000; i += (d = 6 - d)) {
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
        int res[3] { 3 };
        for(auto p : primes) {
            auto it = lower_bound(primes.begin(), primes.end(), n - 3 - p);
            if(it != primes.end() && *it == n - 3 - p) {
                res[1] = p;
                res[2] = *it;
                break;
            }
        }
        sort(res, res + 3);
        cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n';
    }
}