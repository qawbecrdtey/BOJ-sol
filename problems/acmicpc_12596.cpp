#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n; cin >> n;
        set<int> s;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(auto const it = s.find(x); it == s.end()) s.insert(x);
            else s.erase(it);
        }
        cout << *s.begin() << '\n';
    }
}
