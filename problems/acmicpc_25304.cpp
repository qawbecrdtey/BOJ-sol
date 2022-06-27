#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tot, n; cin >> tot >> n;
    while(n--) {
        int a, b; cin >> a >> b; tot -= a * b;
    } if(!tot) cout << "Yes";
    else cout << "No";
}