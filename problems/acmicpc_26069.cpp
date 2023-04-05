#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    map<string, bool> m;
    m["ChongChong"] = true;
    int t; cin >> t; while(t--) {
        string s1, s2; cin >> s1 >> s2;
        if(m[s1] || m[s2]) m[s1] = m[s2] = true;
    } int cnt = 0;
    for(auto [key, val] : m) cnt += val;
    cout << cnt;
}