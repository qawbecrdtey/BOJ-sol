#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    set<string> st;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 1; i + j <= s.size(); j++) {
            st.insert(s.substr(i, j));
        }
    } cout << st.size();
}