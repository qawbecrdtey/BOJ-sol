#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    if(m < 3) cout << "NEWBIE!";
    else if(m <= n) cout << "OLDBIE!";
    else cout << "TLE!";
}