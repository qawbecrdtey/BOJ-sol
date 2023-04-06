#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<int> even, odd, all;
    int n; cin >> n; while(n--) { int x; cin >> x; if(x & 1) odd.push_back(x); else even.push_back(x); all.push_back(x); }
    sort(odd.begin(), odd.end()); sort(even.begin(), even.end()); sort(all.begin(), all.end());
    int res_even = 2000000001, res_odd = 2000000001;
    for(int i = 1; i < odd.size(); i++) res_even = min(res_even, odd[i] - odd[i - 1]);
    for(int i = 1; i < even.size(); i++) res_even = min(res_even, even[i] - even[i - 1]);
    for(int i = 1; i < all.size(); i++) if((all[i] - all[i - 1]) & 1) res_odd = min(res_odd, all[i] - all[i - 1]);
    if(res_even == 2000000001) res_even = -1;
    if(res_odd == 2000000001) res_odd = -1;
    cout << res_even << ' ' << res_odd;
}