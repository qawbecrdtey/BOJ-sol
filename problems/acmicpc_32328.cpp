#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; m[x]++;
    }
    auto const it = next(m.crbegin(), 2);
    cout << it->first << ' ' << it->second;
}
