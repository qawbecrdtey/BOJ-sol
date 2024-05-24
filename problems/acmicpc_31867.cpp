#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string k; cin >> n >> k;
    int e = 0, o = 0;
    for(char c : k) {
        int const b = (c - '0') & 1;
        e += !b;
        o += b;
    }
    if(e > o) cout << 0;
    else if(e < o) cout << 1;
    else cout << -1;
}
