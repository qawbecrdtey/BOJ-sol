#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    map<string, int> m, s;
    string str; int cnt = 0; while(getline(cin, str)) {
        if(str.back() == '\0' || str.back() == '\n') str.pop_back();
        if(str == "0") break;
        m[str]++;
        if(s.find(str) == s.end()) s[std::move(str)] = cnt;
        cnt++;
    }
    vector<pair<string, int>> v{make_move_iterator(s.begin()), make_move_iterator(s.end())};
    sort(v.begin(), v.end(), [](pair<string, int> const &a, pair<string, int> const &b) {
        return a.second < b.second;
    });
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << ": " << m[v[i].first] << '\n';
    }
    cout << "Grand Total: " << cnt;
}
