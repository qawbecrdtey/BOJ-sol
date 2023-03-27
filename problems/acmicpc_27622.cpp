#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; set<int> s; int cnt{}; for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x > 0) {
            if(auto it = s.find(x); it != s.end()) cnt++;
            else s.insert(x);
        }
        else {
            if(auto it = s.find(-x); it == s.end()) cnt++;
            else s.erase(-x);
        }
    } cout << cnt;
}