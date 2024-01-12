#include <iostream>
#include <vector>
using namespace std;
static constexpr int M = 318137;
vector<int> get_primes() {
    vector<int> primes{ 2, 3 };
    vector<bool> visited(M + 1);
    int i = 5, d = 4;
    for(; i * i <= M; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i * 3; j <= M; j += (i << 1)) visited[j] = true;
    }
    for(; i <= M; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
vector<int> get_super_primes(vector<int> const &primes) {
    vector<int> super_primes;
    for(int const p : primes) {
        if(p - 1 >= primes.size()) break;
        super_primes.push_back(primes[p - 1]);
    }
    return super_primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    auto const super_primes = get_super_primes(primes);
    int n; cin >> n; while(n--) { int x; cin >> x; cout << super_primes[x - 1] << '\n'; }
}