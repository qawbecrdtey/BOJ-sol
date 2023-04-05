#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> even, odd;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; if(x & 1) odd.push_back(x); else even.push_back(x);
    }
    cout << min(even.size(), odd.size()) + (odd.size() > even.size() ? (odd.size() - even.size()) / 2 : 0);
}