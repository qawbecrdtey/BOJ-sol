#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<ll> fib{ 1, 1 };
    while(fib[fib.size() - 2] + fib[fib.size() - 1] <= 10000000000000000) {
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
    }
    int n; cin >> n; while(n--) {
        ll x, y; cin >> x >> y;
        for(ll i : fib) {
            if(i > y) break;
            if(x == 1) {
                if(y == i) goto YES;
                continue;
            }
            for(ll j : fib) {
                if(i + j > y) break;
                if(x == 2) {
                    if(y == i + j) goto YES;
                    continue;
                }
                for(ll k : fib) {
                    if(i + j + k > y) break;
                    if(y == i + j + k) goto YES;
                }
            }
        }
        cout << "NO\n";
        continue;
    YES:cout << "YES\n";
    }
}