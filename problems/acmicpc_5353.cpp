#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        auto a = new pair<int, int>[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n, [](pair<int, int> const &a, pair<int, int> const &b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        });
        int cnt = 0;
        int l = 0;
        for(int i = 0; i < n; i++) {
            if(l <= a[i].first) {
                cnt++;
                l = a[i].second;
            }
        }
        cout << cnt << '\n';
        delete[] a;
    }
}