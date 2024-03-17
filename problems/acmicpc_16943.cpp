#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, t; cin >> s >> t;
    if(s.size() > t.size()) { cout << "-1"; return 0; }
    sort(s.begin(), s.end());
    int const tt = stoi(t);
    while(s.front() == '0' && next_permutation(s.begin(), s.end()));
    if(stoi(s) > tt) { cout << "-1"; return 0; }
    string ss = s;
    while(next_permutation(ss.begin(), ss.end())) {
        if(stoi(ss) > tt) {
            cout << s;
            return 0;
        }
        s = ss;
    }
    cout << s;

}