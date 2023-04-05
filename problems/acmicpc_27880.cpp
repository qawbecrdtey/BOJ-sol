#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int res = 0;
    for(int i = 0; i < 4; i++) {
        string s; int n; cin >> s >> n;
        if(s == "Es") res += 21 * n;
        else res += 17 * n;
    } cout << res;
}