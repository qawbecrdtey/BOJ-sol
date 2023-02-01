#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    int nim = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        nim ^= a[i];
    }
    if(!nim) {
        cout << 0;
        return 0;
    }
    //cout << "orig_nim = " << orig_nim << '\n';
    int s = 0;
    while(nim >>= 1) s++;
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += ((a[i] >> s) & 1);
    } cout << res;
}