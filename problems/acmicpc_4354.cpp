#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<uint64_t> factorize(uint64_t n) {
    vector<uint64_t> factors;
    for(uint64_t i = 1; i * i <= n; i++) {
        if(n % i) continue;
        factors.push_back(i);
        if(i * i != n) factors.push_back(n / i);
    }
    sort(factors.begin(), factors.end());
    return factors;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s;
    while(true) {
        cin >> s;
        if(s == ".") return 0;
        auto factors = factorize(s.size());
        uint64_t res = 1;
        for(auto n : factors) {
            for(auto i = n; i < s.size(); i += n) {
                if(!equal(s.begin() + i, s.begin() + i + n, s.begin())) goto NO;
            }
            res = s.size() / n;
            break;
        NO: continue;
        }
        cout << res << '\n';
    }
}
