#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> get_primes() {
    constexpr int M = 100000;
    vector<int> primes{2, 3};
    vector<bool> visited(M);
    int i = 5, d = 4;
    for(; i * i <= M; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j < M; j += (i << 1)) visited[j] = true;
    }
    for(; i < M; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int power(int n, int p) {
    int res = 1;
    for(int i = 0; i < p; i++) res *= n;
    return res;
}
inline bool distinct(int n) {
    set<int> s;
    while(n) {
        if(!s.insert(n % 10).second) return false;
        n /= 10;
    }
    return true;
}
inline bool sum_of_two_primes(vector<int> const &primes, int val) {
    for(auto const p : primes) {
        if((p << 1) >= val) return false;
        if(binary_search(primes.begin(), primes.end(), val - p)) return true;
    }
    return false;
}
inline bool mul_of_two_primes(vector<int> const &primes, int val) {
    for(auto const p : primes) {
        if(p * p > val) return false;
        if(val % p == 0 && binary_search(primes.begin(), primes.end(), val / p)) return true;
    }
    return false;
}
int main() {
    auto const primes = get_primes();
    int k, m; cin >> k >> m;
    auto const n = power(10, k);
    int res = 0;
    for(int i = power(10, k - 1); i < n; i++) {
        if(!distinct(i)) continue;
        if(!sum_of_two_primes(primes, i)) continue;
        int val = i;
        while(val % m == 0) val /= m;
        if(!mul_of_two_primes(primes, val)) continue;
        res++;
    }
    cout << res;
}