#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<string, string> m;
    auto a = new string[n];
    if(n & 1) goto BAD;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(a[i] == s) goto BAD;
        if(auto it = m.find(s); it != m.end() && it->second != a[i]) goto BAD;
        m[a[i]] = s;
    }
    cout << "good"; return 0;
BAD:cout << "bad";
}