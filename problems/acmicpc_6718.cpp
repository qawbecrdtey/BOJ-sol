#include <iostream>
#include <vector>
using namespace std;
inline vector<int> get_primes(int n) {
    vector<int> primes(max(5, n + 1));
    fill(primes.begin(), primes.end(), 1);
    primes[0] = primes[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            for(int j = i * i; j <= n; j += i) primes[j] = 0;
        }
    }
    return primes;
}
inline vector<int> eval(vector<int> &&a) {
    vector<int> res((a.size() << 1)  - 1);
    for(int i = 0; i < a.size(); i++) {
        if(!a[i]) continue;
        for(int j = i; j < a.size(); j++) {
            res[i + j] += a[i] * a[j];
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m = 0;
    vector<int> v;
    while(cin >> n) {
        if(!n) break;
        v.push_back(n);
        m = max(m, n);
    }
    auto const mult = eval(get_primes(m));
    for(auto const now : v) {
        cout << mult[now] << '\n';
    }
}