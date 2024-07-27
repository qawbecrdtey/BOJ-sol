#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<string, int> m;
    while(n--) { string s; cin >> s; m[s]++; }
    auto a = new pair<string, int>[m.size()];
    int idx = 0; auto it = m.begin();
    while(it != m.end()) {
        a[idx] = *it;
        idx++; ++it;
    }
    sort(a, a + m.size(), [](auto a, auto b) { return a.second < b.second; });
    int sum = 0;
    for(int i = 0; i < m.size() - 1; i++) {
        sum += a[i].second;
    }
    if(a[m.size() - 1].second > sum) cout << a[m.size() - 1].first;
    else cout << "NONE";
}
