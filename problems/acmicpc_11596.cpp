#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[3], b[3]; for(int &i : a) cin >> i; for(int &i : b) cin >> i;
    sort(a, a + 3); sort(b, b + 3);
    if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) cout << "YES";
    else cout << "NO";
}