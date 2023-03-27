#include <iostream>
using namespace std;
static constexpr bool str[] = {true, false, false, true, false, false, true, false, false, false};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    auto a = new bool[n];
    int res = 0;
    for(int i = 0; i < n; i++) {
        a[i] = str[i % 10];
        res += a[i];
    }
    while(q--) {
        int x; cin >> x; x--;
        a[x] = !a[x];
        if(!a[x]) res--;
        else res++;
        cout << res << '\n';
    }
}