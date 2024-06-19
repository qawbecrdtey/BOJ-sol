#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    map<string, int> m; while(true) {
        string s; cin >> s;
        if(s == "000-00-0000") break;
        m[std::move(s)]++;
    }
    for(auto &[k, v] : m) {
        if(v == 1) continue;
        cout << k << '\n';
    }
}
