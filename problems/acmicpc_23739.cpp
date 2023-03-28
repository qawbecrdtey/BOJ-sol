#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, r{}; cin >> n;
    int remain = 30;
    while(n--) {
        int x; cin >> x;
        if(x > remain * 2) {
            remain = 30;
            continue;
        }
        if(x >= remain) {
            remain = 30;
            r++;
            continue;
        }
        remain -= x;
        r++;
    }
    cout << r;
}