#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<string, pair<int, int>> m;
    for(int i = 0; i < n; i++) {
        string s; cin >> s; m[std::move(s)].second = i;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s; m[std::move(s)].first = 1;
    }
    vector<pair<string, pair<int, int>>> v{m.begin(), m.end()};
    sort(v.begin(), v.end(), [](auto const &a, auto const &b) {
        return a.second.first > b.second.first || (a.second.first == b.second.first && a.second.second > b.second.second);
    });
    for(auto const &[s, p] : v) {
        cout << s << '\n';
    }
}
