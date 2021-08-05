#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    auto a = new int[t + 1]();
    set<int> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for(auto now : s) {
        for(int i = now; i <= t; i += now) {
            a[i] = 1;
        }
    }
    int res = 0;
    for(int i = 1; i <= t; i++) {
        res += a[i];
    }
    cout << res;
}