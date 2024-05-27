#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<string, vector<string>> m;
    while(n--) {
        string s, t; cin >> s >> t;
        if(t == "-") continue;
        m[std::move(t)].push_back(std::move(s));
    }
    vector<vector<string>> res;
    for(auto const &[key, val]: m) {
        if(val.size() == 2) {
            res.emplace_back(val);
        }
    }
    cout << res.size();
    for(auto const &now : res) {
        cout << '\n' << now[0] << ' ' << now[1];
    }
}
