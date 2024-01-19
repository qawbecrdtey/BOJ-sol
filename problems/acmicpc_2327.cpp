#include <iostream>
#include <limits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int h, n; cin >> h >> n;
    auto prev = new int[h + 1];
    auto now = new int[h + 1];
    prev[0] = numeric_limits<int>::max();
    fill(prev + 1, prev + h + 1, -1);
    for(int i = 0; i < n; i++) {
        copy(prev, prev + h + 1, now);
        int x, y; cin >> x >> y;
        for(int j = x; j <= h; j++) {
            if(prev[j - x] != -1) {
                now[j] = max(now[j], min(y, prev[j - x]));
            }
        }
        swap(prev, now);
    }
    cout << prev[h];
}