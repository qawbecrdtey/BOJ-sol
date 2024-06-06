#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes() {
    vector<int> primes{2, 3};
    vector<bool> visited(20001);
    int i = 5, d = 4;
    for(; i * i <= 20000; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j <= 20000; j += (i << 1)) visited[j] = true;
    }
    for(; i <= 20000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n];
    auto const primes = get_primes();
    int idx = -1, val = 0, p = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];
        int current_prime = 1;
        for(auto const prime : primes) {
            if(prime > x) break;
            if(x % prime == 0) {
                current_prime = prime;
                while(x % prime == 0) {
                    x /= prime;
                }
            }
        }
        if(x != 1) {
            current_prime = x;
        }
        if(p < current_prime) {
            p = current_prime;
            val = a[i];
            idx = i;
        }
    }
    cout << val;
}
