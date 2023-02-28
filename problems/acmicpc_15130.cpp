#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[10], b[2], c{};
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
        if(a[i]) b[c++] = i;
    }
    if((a[b[1]] - a[b[0]]) % (b[1] - b[0])) {
        cout << -1;
        return 0;
    }
    int d = (a[b[1]] - a[b[0]]) / (b[1] - b[0]);
    int a0 = a[b[0]] - b[0] * d;
    for(int i = 0; i < 10; i++) {
        cout << a0 + i * d << ' ';
    }
}