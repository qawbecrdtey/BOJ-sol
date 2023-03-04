#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto arr = new int[n + 2];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int m; cin >> m; while(m--) {
        int x, y; cin >> x >> y;
        switch(x) {
            case 1: for(int i = y; i <= n; i += y) arr[i] = 1 - arr[i]; break;
            case 2: {
                int left = y, right = y;
                do {
                    if(arr[left] != arr[right]) break;
                    left--; right++;
                } while(left && right <= n);
                for(int i = left + 1; i < right; i++) {
                    arr[i] = 1 - arr[i];
                }
            } break;
            default: __builtin_unreachable();
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
        if(i % 20 == 0) cout << '\n';
    }
}