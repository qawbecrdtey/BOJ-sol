#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    set<string> s;
    while(n--) {
        string x; cin >> x; s.insert(x);
    }
    int cnt = 0;
    while(m--) {
        string x; cin >> x;
        cnt += (s.find(x) == s.end());
    } cout << cnt;
}