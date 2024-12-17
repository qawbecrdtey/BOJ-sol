#include <iostream>
#include <string>
#include <vector>
using namespace std;
static constexpr int arr[] {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int x, y; string s, t, u; cin >> x >> y >> s >> t;
    for(int i = 0; i < max(s.size(), t.size()); i++) {
        if(i < s.size()) u.push_back(s[i]);
        if(i < t.size()) u.push_back(t[i]);
    }
    vector<int> v;
    for(char c : u) v.push_back(arr[c - 'A']);
    while(v.size() > 2) {
        for(int x : v) cout << x << ' '; cout << '\n';
        vector<int> u;
        for(int i = 1; i < v.size(); i++) {
            u.push_back((v[i - 1] + v[i]) % 10);
        }
        v = std::move(u);
    }
    if(v[0] != 0) cout << v[0];
    cout << v[1] << '%';
}
