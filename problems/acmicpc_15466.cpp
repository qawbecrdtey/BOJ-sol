#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int m, n; cin >> m >> n;
        set<int> a, b;
        for(int i = 0; i < m; i++) {
            int x; cin >> x; a.insert(x);
        }
        for(int i = 0; i < n; i++) {
            int x; cin >> x; b.insert(x);
        }
        set<int> in, un;
        for(int now : a) {
            un.insert(now);
            if(b.find(now) != b.end()) in.insert(now);
        }
        for(int now : b) un.insert(now);
        cout << ((in.size() << 1) > un.size()) << '\n';
    }
}