#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    set<string> s;
    int n; cin >> n; while(n--) {
        string str; cin >> str;
        string cur = str;
        for(int i = 0; i < str.size(); i++) {
            if(cur < str) str = cur;
            cur = cur.substr(1) + cur[0];
        }
        s.insert(str);
    }
    cout << s.size();
}