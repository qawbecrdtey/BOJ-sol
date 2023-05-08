#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
struct info {
    int tier;
    int val;
    bool operator<(info const &i) const { return tier < i.tier || (tier == i.tier && val > i.val); }
    bool operator==(info const &i) const { return tier == i.tier && val == i.val; }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new info[n];
    map<string, int> m;
    m["B"] = 1;
    m["S"] = 2;
    m["G"] = 3;
    m["P"] = 4;
    m["D"] = 5;
    string mr[6] = {"", "B", "S", "G", "P", "D"};
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i].tier = m[s.substr(0, 1)];
        a[i].val = stoi(s.substr(1));
    }
    bool flag = true;
    for(int i = 1; i < n; i++) {
        if(a[i - 1] < a[i]) continue;
        cout << "KO\n";
        auto b = new info[n];
        copy(a, a + n, b);
        sort(b, b + n);
        for(int j = 0; j < n; j++) {
            if(a[j] == b[j]) continue;
            cout << mr[b[j].tier] << b[j].val << ' ';
        }
        return 0;
    }
    cout << "OK";
}