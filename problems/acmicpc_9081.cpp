#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    while(n--) {
        string s, t; cin >> s; t = s;
        if(next_permutation(s.begin(), s.end())) cout << s << '\n';
        else cout << t << '\n';
    }
}