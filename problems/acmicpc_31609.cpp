#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    bool a[10]{};
    int n; cin >> n;
    while(n--) {
        int x; cin >> x; a[x] = true;
    }
    for(int i = 0; i < 10; i++) {
        if(a[i]) cout << i << '\n';
    }
}
