#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, cnt{}; cin >> n; set<string> s; while(n--) {
        string t; cin >> t; cnt += (!s.insert(std::move(t)).second);
    } cout << cnt;
}