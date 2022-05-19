#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        int a[10]{};
        vector<pair<int, int>> v;
        for(char c : s) {
            a[c - '0']++;
        }
        for(char c : s) {
            v.emplace_back(c - '0', a[c - '0']--);
        }
        if(!next_permutation(v.begin(), v.end())) {
            cout << "BIGGEST\n";
        } else {
            for(auto [now, x] : v) cout << now;
            cout << '\n';
        }
    }
}