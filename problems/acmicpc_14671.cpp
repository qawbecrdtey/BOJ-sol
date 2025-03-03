#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    set<pair<int, int>> s;
    while(k--) {
        int x, y; cin >> x >> y;
        s.insert({x % 2, y % 2});
    }
    if(s.size() == 4) cout << "YES";
    else cout << "NO";
}
