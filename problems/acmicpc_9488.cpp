#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
ostream &operator<<(ostream &os, __int128 n) {
    if(!n) os << '0';
    else {
        string s;
        while(n) {
            s.push_back(char('0' + n % 10));
            n /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
    return os;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    while(true) {
        cin >> n;
        if(!n) return 0;
        __int128 res = (__int128)n * (n + 1) / 2 * (n + 2) / 3;
        cout << res << '\n';
    }
}