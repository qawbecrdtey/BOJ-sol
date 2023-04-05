#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new pair<int, string>[n];
        for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
        sort(a, a + n);
        for(int i = n - 1; i >= 0; i--) {
            cout << a[i].second;
            if(i) cout << ", ";
        } cout << '\n';
        delete[] a;
    }
}