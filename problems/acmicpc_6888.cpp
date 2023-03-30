#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int x, y; cin >> x >> y;
    while(x <= y) {
        cout << "All positions change in year " << x << '\n';
        x += 60;
    }
}