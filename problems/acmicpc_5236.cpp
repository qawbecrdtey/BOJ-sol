#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        cout << "The longest decreasing suffix of " << s << " is ";
        string r;
        for(char c : s) {
            if(r.empty() || r.back() > c) r.push_back(c);
            else r = string(1, c);
        } cout << r << '\n';
    }
}