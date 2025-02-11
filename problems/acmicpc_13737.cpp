#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
bool all_equal(int n, ll const *a) {
    for(int i = 1; i < n; i++) {
        if(a[i] != a[0]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<ll*> v;
    v.push_back(new ll[n]);
    for(int i = 0; i < n; i++) cin >> v.back()[i];
    int cur_n = n, cur_deg = 0;
    while(cur_n > 1) {
        if(all_equal(cur_n, v.back())) break;
        auto a = new ll[--cur_n];
        for(int i = 0; i < cur_n; i++) {
            a[i] = v.back()[i + 1] - v.back()[i];
        }
        cur_deg++; v.push_back(a);
    }
    cout << cur_deg << ' ';
    ll val = v.back()[0];
    for(int i = static_cast<int>(v.size()) - 2; i >= 0; i--) {
        val += v[i][cur_n++];
    }
    cout << val;
}
