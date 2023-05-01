#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[4]; for(int &i : a) cin >> i; int b; cin >> b;
    sort(a, a + 4); cout << (a[0] == a[3] || (a[0] + b == a[3] && a[1] == a[3]));
}