#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; set<string> s;
    while(n--) { string t; cin >> t; s.insert(std::move(t)); }
    bool will_close = false; cin >> n; while(n--) {
        string t; cin >> t;
        if(auto it = s.find(t); it != s.end()) {
            cout << (will_close ? "Closed by " : "Opened by ") << t << '\n';
            will_close = !will_close;
        } else cout << "Unknown " << t << '\n';
    }
}