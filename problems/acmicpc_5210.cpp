#include <iostream>
#include <string>
#include <vector>
using namespace std;
inline int getint() {
    string s;
    getline(cin, s);
    return stoi(s);
}
inline char upper(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a' + 'A';
    return c;
}
inline char lower(char c) {
    if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = getint();
    for(int tt = 1; tt <= t; tt++) {
        cout << "Data Set " << tt << ":\n";
        int n = getint();
        vector<string> v;
        for(int i = 0; i < n; i++) {
            string s; getline(cin, s); v.push_back(s);
        }
        string ack; getline(cin, ack);
        for(auto const &s : v) {
            int idx = 0;
            for(char c : s) {
                if(ack[idx] == upper(c) || ack[idx] == lower(c)) {
                    idx++;
                }
                if(idx == ack.size()) {
                    cout << s << '\n';
                    break;
                }
            }
        }
    }
}