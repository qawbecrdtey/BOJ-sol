#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    set<string> s; string t; while(cin >> t) {
        auto [a, b] = s.insert(t);
        if(!b) {
            cout << "no";
            return 0;
        }
    } cout << "yes";
}