#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct info { string s; int n; };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new info[n];
    for(int i = 0; i < n; i++) cin >> a[i].s >> a[i].n;
    sort(a, a + n, [](info const &a, info const &b) {
        return a.n > b.n || (a.n == b.n && a.s < b.s);
    });
    cout << a[0].s;
}