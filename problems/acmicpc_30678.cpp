#include <iostream>
using namespace std;
int power(int n, int p) {
    if(!p) return 1;
    if(p == 1) return n;
    int const r = power(n, p >> 1);
    return r * r * power(n, p & 1);
}
void draw(char **canvas, int x_lo, int y_lo, int l, int n) {
    if(!n) {
        canvas[x_lo][y_lo] = '*';
        return;
    }
    int const m = l / 5;
    draw(canvas, x_lo + m * 2, y_lo, m, n - 1);
    draw(canvas, x_lo + m * 2, y_lo + m, m, n - 1);
    draw(canvas, x_lo + m * 3, y_lo + m, m, n - 1);
    draw(canvas, x_lo + m * 4, y_lo + m, m, n - 1);
    draw(canvas, x_lo, y_lo + m * 2, m, n - 1);
    draw(canvas, x_lo + m, y_lo + m * 2, m, n - 1);
    draw(canvas, x_lo + m * 2, y_lo + m * 2, m, n - 1);
    draw(canvas, x_lo + m * 3, y_lo + m * 2, m, n - 1);
    draw(canvas, x_lo + m * 2, y_lo + m * 3, m, n - 1);
    draw(canvas, x_lo + m * 3, y_lo + m * 3, m, n - 1);
    draw(canvas, x_lo + m * 4, y_lo + m * 3, m, n - 1);
    draw(canvas, x_lo + m * 2, y_lo + m * 4, m, n - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const l = power(5, n);
    auto canvas = new char*[l];
    for(int i = 0; i < l; i++) {
        canvas[i] = new char[l + 1];
        fill(canvas[i], canvas[i] + l, ' ');
        canvas[i][l] = '\0';
    }
    draw(canvas, 0, 0, l, n);
    for(int i = 0; i < l; i++) {
        cout << canvas[i] << '\n';
    }
}