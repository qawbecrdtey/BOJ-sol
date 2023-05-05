#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[3], b[3], l, s{}; for(int &i : a) cin >> i; for(int &i : b) { cin >> i; s += i; } cin >> l;
    vector<int> v;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < b[i]; j++) {
            v.push_back(-a[i]);
        }
    } sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) v[i] = -v[i];
    for(int i = 1; i < v.size(); i++) v[i] += v[i - 1];
    auto res = lower_bound(v.begin(), v.end(), l) - v.begin();
    if(res == v.size()) cout << 0;
    else cout << res + 1;
}