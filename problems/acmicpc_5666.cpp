#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(2);
    int a, b; while(cin >> a >> b) {
        cout << fixed << static_cast<long double>(a) / b << '\n';
    }
}
