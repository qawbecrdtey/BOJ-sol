#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, k; cin >> a >> k;
    if(!k) cout << a;
    else cout << ((a & 1) ? a : 1);
}