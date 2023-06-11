#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, cnt{}; cin >> n >> m;
    while(n--) {
        string s; cin >> s;
        bool a[26]{};
        bool flag = true;
        for(char c : s) {
            if(a[c - 'A'] || c - 'A' >= m) { flag = false; break; }
            a[c - 'A'] = true;
        } cnt += flag;
    } cout << cnt;
}