#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<int, int> m;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x; m[x] = i;
    }
    for(auto const [l, r] : m) {
        cout << r << '\n';
    }
}
