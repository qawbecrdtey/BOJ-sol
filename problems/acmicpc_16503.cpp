#include <algorithm>
#include <iostream>
using namespace std;
inline int calc(int a, char const s[2], int b) {
    switch(*s) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: __builtin_unreachable();
    }
}
int main() {
    int a, b, c;
    char s[2], t[2];
    cin >> a >> s >> b >> t >> c;
    int res[2]{ calc(calc(a, s, b), t, c), calc(a, s, calc(b, t, c)) };
    if(res[0] > res[1]) swap(res[0], res[1]);
    cout << res[0] << '\n' << res[1];
}