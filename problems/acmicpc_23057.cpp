#include <iostream>
#include <set>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    set<ll> s;
    for(int i = 1; i < (1 << n); i++) {
        ll m = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) m += a[j];
        }
        s.insert(m);
    }
    cout << sum - static_cast<ll>(s.size());
}
