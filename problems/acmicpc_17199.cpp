#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto arr = new int[n + 1];
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[a]++;
    } int res = 0;
    for(int i = 1; i <= n; i++) {
        if(!res && !arr[i]) {
            res = i;
            continue;
        } if(res && !arr[i]) {
            cout << -1;
            return 0;
        }
    } cout << res;
}