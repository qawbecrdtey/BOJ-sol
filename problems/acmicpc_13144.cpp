#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0;
    auto contains = new bool[n + 1]();
    int cnt = 0;
    long long res = 0;
    while(l != n) {
        if(r == n) {
            l++;
            continue;
        }
        while(contains[a[r]]) {
            contains[a[l]] = false;
            l++;
            cnt--;
        }
        contains[a[r]] = true;
        r++;
        cnt++;
        res += r - l;
    }
    cout << res;
}
