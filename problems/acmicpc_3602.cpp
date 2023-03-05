#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b; cin >> a >> b;
    if(!a && !b) {
        cout << "Impossible";
        return 0;
    }
    if(a > b) swap(a, b);
    if(a < b) b = a + 1;
    a = a + b;
    for(b = 0; (b + 1) * (b + 1) <= a; b++);
    cout << b;
}