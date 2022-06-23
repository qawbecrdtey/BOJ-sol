#pragma GCC optimize("O2")
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; string s; cin >> t; while(t--) {
        int sum = 0; cin >> s; for(char c : s) sum += c - '0';
        cout << (sum % 9 ? "NO" : "YES") << '\n';
    }
}