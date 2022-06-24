#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    unsigned long idx = 0, cnt = 0, start;
    while(idx < s.size()) {
        start = idx++;
        while(idx < s.size() && s[idx] >= 'a' && s[idx] <= 'z') idx++;
        if(idx == s.size()) {
            cout << cnt;
            return 0;
        } cnt += (4 - (idx - start) % 4) % 4;
    }
}