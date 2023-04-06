#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string m[] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };
    //map<string, int> m; m["Re"] = 0; m["Pt"] = 1; m["Cc"] = 2; m["Ea"] = 3; m["Tb"] = 4; m["Cm"] = 5; m["Ex"] = 6;
    map<string, int> cnt; int total = 0; string s; while(cin >> s) cnt[s]++, total++;
    cout.precision(2);
    for(auto const &it : m) {
        cout << it << ' ' << cnt[it] << ' ' << fixed << double(cnt[it]) / double(total) << '\n';
    } cout << "Total " << total << " 1.00";
}