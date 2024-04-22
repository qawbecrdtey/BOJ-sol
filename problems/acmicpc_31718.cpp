#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; while(!(x & 1)) x >>= 1;
        m[x]++;
    }
    int res = 0;
    for(auto [k, v] : m) {
        if(res < v) res = v;
    }
    cout << res;
}