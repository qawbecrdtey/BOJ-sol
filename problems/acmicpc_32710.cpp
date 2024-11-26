#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    if(n == 1) goto YES;
    for(int i = 2; i < 10; i++) {
        if(n % i || n / i > 9) continue;
        goto YES;
    }
    cout << "0";
    return 0;
YES:cout << "1";
}
