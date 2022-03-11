#include <iostream>
using namespace std;
inline int ccw(int const a[2], int const b[2], int const c[2]) {
    int res = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (a[1] * b[0] + b[1] * c[0] + c[1] * a[0]);
    if(res > 0) return 1;
    if(!res) return 0;
    return -1;
}
inline bool intersect(int const a[2], int const b[2], int const c[2], int const d[2]) {
    return (ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0);
}
int main() {
    int a[4][2];
    for(auto &i : a) {
        for(auto &j : i) {
            std::cin >> j;
        }
    }
    cout << intersect(a[0], a[1], a[2], a[3]);
}