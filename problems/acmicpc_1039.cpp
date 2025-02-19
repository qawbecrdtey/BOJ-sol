#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; int k; cin >> s >> k;
    int const n = static_cast<int>(s.size());
    queue<pair<string, int>> q;
    q.emplace(std::move(s), 0);
    set<pair<string, int>> st;
    set<string> res;
    while(!q.empty()) {
        auto [now_s, now_k] = std::move(q.front()); q.pop();
        if(!st.insert({now_s, now_k}).second) continue;
        if(now_k == k) {
            res.insert(std::move(now_s));
            continue;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(!i && now_s[j] == '0') continue;
                string new_s(now_s);
                swap(new_s[i], new_s[j]);
                q.emplace(std::move(new_s), now_k + 1);
            }
        }
    }
    if(res.empty()) {
        cout << -1; return 0;
    }
    vector<int> v(res.size());
    transform(make_move_iterator(res.begin()), make_move_iterator(res.end()), v.begin(), [](string s) {
        return stoi(s);
    });
    cout << *max_element(v.cbegin(), v.cend());
}
