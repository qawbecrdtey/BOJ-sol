#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    int len = 0;
    auto b = new int[100001]();
    while(l < n) {
        if(r >= n) {
            b[a[l]]--;
            l++;
        }
        else if(l == r) {
            b[a[r]]++;
            r++;
            len = max(len, 1);
        }
        else if(b[a[r]] == k) {
            b[a[l]]--;
            l++;
        }
        else {
            b[a[r]]++;
            r++;
            len = max(len, r - l);
        }
    }
    cout << len;
}