#include <iostream>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n && i <= 9; i++) {
        if(10 - i > m) continue;
        cnt++;
    }
    cout << "There " << (cnt == 1 ? "is " : "are ") << cnt << (cnt == 1 ? " way " : " ways ") << "to get the sum 10.";
}
