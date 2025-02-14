#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    set<int> odd, even;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; if(x & 1) odd.insert(x); else even.insert(x);
    }
    if(odd.size() < even.size()) {
        int res = 2;
        for(int x : even) {
            if(x == res) res += 2;
            else break;
        }
        cout << res;
    }
    else {
        int res = 1;
        for(int x : odd) {
            if(x == res) res += 2;
            else break;
        }
        cout << res;
    }
}
