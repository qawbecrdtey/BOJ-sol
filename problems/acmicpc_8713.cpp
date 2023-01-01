#include <iostream>
#include <string>
using namespace std;
inline string stringify(int n) {
    if(n < 0) return "(" + to_string(n) + ")";
    return to_string(n);
}
inline char maxchar(int a, int b) {
    int arr[] { a + b, a - b, a * b };
    if(arr[0] > arr[1] && arr[0] > arr[2]) return '+';
    if(arr[1] > arr[0] && arr[1] > arr[2]) return '-';
    if(arr[2] > arr[0] && arr[2] > arr[1]) return '*';
    return '\0';
}
inline int result(int a, int b, char c) {
    switch(c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: __builtin_unreachable();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b; cin >> a >> b;
    char const c = maxchar(a, b);
    if(c == '\0') cout << "NIE";
    else cout << stringify(a) << c << stringify(b) << '=' << stringify(result(a, b, c));
}