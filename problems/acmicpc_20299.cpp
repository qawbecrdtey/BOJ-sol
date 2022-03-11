#include <iostream>
#include <vector>
using namespace std;
struct info { int a, b, c; info(int a, int b, int c) : a(a), b(b), c(c) {} };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k, l;
    cin >> n >> k >> l;
    vector<info> v;
    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        if(a >= l && b >= l && c >= l && a + b + c >= k) {
            v.emplace_back(a, b, c);
        }
    }
    cout << v.size() << '\n';
    for(auto [a, b, c] : v) {
        cout << a << ' ' << b << ' ' << c << ' ';
    }
}