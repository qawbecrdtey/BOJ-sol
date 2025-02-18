#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    for(int i = 1; i <= s.size(); i++) {
        set<string> st;
        for(int j = 0; j <= n - i; j++) {
            if(!st.insert(s.substr(j, i)).second) {
                goto NO;
            }
        }
        cout << i;
        return 0;
NO:     continue;
    }
}
