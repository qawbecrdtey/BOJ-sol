#include <iostream>
using namespace std;
pair<int, int> play(char const a, char const b) {
    if(a == b) return {0, 0};
    if((a == 'R' && b == 'P') || (a == 'S' && b == 'R') || (a == 'P' && b == 'S')) return {0, 1};
    return {1, 0};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new char[n + 1]; cin >> a;
    auto b = new char[n + 1]; cin >> b;
    int A = 0, B = 0;
    for(int i = 0; i < n; i++) {
        auto const [x, y] = play(a[i], b[i]);
        A += x; B += y;
    }
    cout << A << ' ' << B;
}
