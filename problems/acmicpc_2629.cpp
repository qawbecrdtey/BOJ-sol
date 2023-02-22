#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    set<int> s; s.insert(0);
    while(n--) {
        int x; cin >> x;
        set<int> t(s);
        for(int now : t) {
            s.insert(x + now);
            s.insert(abs(x - now));
        }
    } cin >> n; while(n--) {
        int x; cin >> x;
        if(s.find(x) != s.end()) cout << "Y ";
        else cout << "N ";
    }
}