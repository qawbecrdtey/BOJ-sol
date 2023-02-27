#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b; while(cin >> a >> b) {
        if(!a && !b) return 0;
        cout << min({a * 30 + b * 40, a * 35 + b * 30, a * 40 + b * 20}) << '\n';
    }
}