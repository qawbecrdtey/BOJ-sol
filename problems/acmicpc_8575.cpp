#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> split(string s) {
    vector<int> res;
    int cnt = 0;
    for(char c : s) {
        if(c == 'W') {
            if(cnt) {
                res.push_back(cnt);
                cnt = 0;
                continue;
            }
        }
        else cnt++;
    }
    if(cnt) res.push_back(cnt);
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    auto const v = split(s);
    int res = 0;
    for(auto const now : v) {
        res += (now + 2) / 3;
    } cout << res;
}
