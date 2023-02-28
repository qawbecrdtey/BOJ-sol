#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b, i; cin >> a >> b;
    for(i = 0; i < a && i < b; i++) cout << i << ':' << i + 1 << '\n' << i + 1 << ':' << i + 1 << '\n';
    for(; i < a; i++) cout << i + 1 << ':' << b << '\n';
    for(; i < b; i++) cout << a << ':' << i + 1 << '\n';
}