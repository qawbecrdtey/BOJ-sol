#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<string, int> m;
    while(n--) {
        string s; int x; cin >> s >> x; m[std::move(s)] += x;
    }
    for(auto const &[s, x] : m) {
        cout << s << ' ' << x << '\n';
    }
}
