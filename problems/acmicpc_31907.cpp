#include <iostream>
using namespace std;
void draw(char **a, int x, int y, char c, int n) {
    for(int i = x; i < x + n; i++) {
        fill(a[i] + y, a[i] + y + n, c);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new char*[n * 3];
    for(int i = 0; i < n * 3; i++) {
        a[i] = new char[n * 4 + 2];
        fill(a[i], a[i] + n * 4, '.');
        a[i][n * 4] = '\n';
        a[i][n * 4 + 1] = '\0';
    }
    draw(a, 0, 0, 'G', n);
    draw(a, n, n, 'I', n);
    draw(a, 2 * n, 2 * n, 'S', n);
    draw(a, n, 3 * n, 'T', n);
    for(int i = 0; i < n * 3; i++) cout << a[i];
}
