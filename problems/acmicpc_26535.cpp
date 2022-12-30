#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int x = 1; while(x * x < n) x++;
    x += 2; for(int i = 0; i < x; i++) {
        cout << 'x' << string(x - 2, i == 0 || i == x - 1 ? 'x' : '.') << 'x' << '\n';
    }
}