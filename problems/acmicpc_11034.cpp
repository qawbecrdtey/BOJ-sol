#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b, c; while(cin >> a >> b >> c) {
        int cnt = 0;
        while(b - a > 1 || c - b > 1) {
            if(b - a < c - b) {
                a = b;
                b++;
            }
            else {
                c = b;
                b--;
            }
            cnt++;
        }
        cout << cnt << '\n';
    }
}