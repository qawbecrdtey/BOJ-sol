#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes() {
    vector<int> primes{ 2, 3 };
    vector<bool> visited(3163);
    int i = 5, d = 4;
    for(; i * i < 3163; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int j = i; j < 3163; j += (i << 1)) visited[j] = true;
        }
    }
    for(; i < 3163; i++) {
        if(!visited[i]) primes.push_back(i);
    } return primes;
}
inline int count(vector<int> const &primes, int n) {
    int res = 1;
    for(int p : primes) {
        if(n == 1 || p * p > n) break;
        int cnt = 1;
        while(!(n % p)) { n /= p; cnt++; }
        res *= cnt;
    } if(n != 1) res *= 2;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const primes = get_primes();
    int t; cin >> t; while(t--) {
        int a, b; cin >> a >> b;
        int max = 0;
        for(int i = a; i <= b; i++) {
            int const cnt = count(primes, i);
            if(max < cnt) max = cnt;
        } cout << max << '\n';
    }
}