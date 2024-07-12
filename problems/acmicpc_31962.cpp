#include <iostream>
#include <optional>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, x; cin >> n >> x;
    optional<int> res;
    while(n--) {
        int a, b; cin >> a >> b;
        if(a + b > x) continue;
        if(!res || *res < a) res = a;
    }
    if(!res) cout << -1;
    else cout << *res;
}
