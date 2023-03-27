#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; char c[2];
    int d{}, p{};
    while(n--) {
        cin >> c; bool const x = (*c == 'D'); d += x; p += !x;
        if(d == p + 2 || p == d + 2) break;
    } cout << d << ':' << p;
}