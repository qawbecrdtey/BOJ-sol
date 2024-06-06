#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += (s[i] != t[i]);
    } cout << res;
}
