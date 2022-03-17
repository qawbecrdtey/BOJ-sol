#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int idx = 1;
    for(int i = 0; i < n; i++) {
        while(idx < n && a[i] == a[idx]) idx++;
        if(idx == n) cout << "-1 ";
        else cout << idx + 1 << ' ';
    }
}