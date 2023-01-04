#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
struct rat {
    ll num, den;
    bool operator<(rat const &r) const { return r.den * num < den * r.num; }
    friend ostream &operator<<(ostream &os, rat const &r) {
        os << r.num << '/' << r.den;
        return os;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<rat> v;
    for(ll num = 1; num < n; num++) {
        for(ll den = num + 1; den <= n; den++) {
            if(gcd(num, den) != 1) continue;
            v.push_back({ num, den });
        }
    } v.push_back({ 0, 1 });
    v.push_back({ 1, 1 });
    sort(v.begin(), v.end());
    cout << v.size();
    for(rat const &now : v) cout << '\n' << now;
}