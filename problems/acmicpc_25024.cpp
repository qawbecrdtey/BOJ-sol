#include <iostream>
using namespace std;
constexpr char yes[] = "Yes";
constexpr char no[] = "No";
inline bool calendar(int a, int b) {
    switch(a) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return b > 0 && b <= 31;
        case 4:
        case 6:
        case 9:
        case 11: return b > 0 && b < 31;
        case 2: return b > 0 && b < 30;
        default: return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a, b; cin >> a >> b;
        cout << (a < 24 && b < 60 ? yes : no) << ' ';
        cout << (calendar(a, b) ? yes : no) << '\n';
    }
}