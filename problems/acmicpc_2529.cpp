#include <algorithm>
#include <iostream>
using namespace std;
inline bool f(int n, int const *a, bool const *b) {
    for(int i = 0; i < n; i++) {
        if((a[i] < a[i + 1]) ^ b[i]) return false;
    } return true;
}
int main() {
    int n; cin >> n;
    int a[10];
    auto b = new bool[n];
    for(int i = 0; i < n; i++) {
        char s[2]; cin >> s;
        b[i] = (*s == '<');
    }
    for(int i = 0; i < 10; i++) a[i] = 9 - i;
    while(!f(n, a, b)) prev_permutation(a, a + 10);
    for(int i = 0; i <= n; i++) cout << a[i];
    cout << '\n';
    for(int i = 0; i < 10; i++) a[i] = i;
    while(!f(n, a, b)) next_permutation(a, a + 10);
    for(int i = 0; i <= n; i++) cout << a[i];
}