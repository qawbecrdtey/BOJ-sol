#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    auto a = new ll[n + 1];
    auto sum = new ll[n + 1];
    sum[0] = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    if(sum[n] & 3) { cout << 0; return 0; }
    ll const s = sum[n] >> 2;
    vector<ll> one, two, three;
    for(ll i = 1; i < n; i++) {
        if(sum[i] == s) one.push_back(i);
        if(sum[i] == 2 * s) two.push_back(i);
        if(sum[i] == 3 * s) three.push_back(i);
    }
    auto dp23 = new ll[two.size() + 1];
    dp23[two.size()] = 0;
    for(ll i = two.size() - 1; i >= 0; i--) {
        dp23[i] = three.end() - upper_bound(three.begin(), three.end(), two[i]) + dp23[i + 1];
    }
    auto dp12 = new ll[one.size() + 1];
    dp12[one.size()] = 0;
    for(ll i = one.size() - 1; i >= 0; i--) {
        ll j = upper_bound(two.begin(), two.end(), one[i]) - two.begin();
        if(j == two.size() + 1) dp12[i] = 0;
        else dp12[i] = dp23[j] + dp12[i + 1];
    }
    cout << dp12[0];
}
