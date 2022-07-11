#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s1, s2; cin >> s1 >> s2;
        cout << (s1 == s2 ? "OK\n" : "ERROR\n");
    }
}