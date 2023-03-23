#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int x, y; cin >> x >> y;
    char a[11][12]; bool visited[11][12]{}; for(int i = 1; i <= 10; i++) cin >> (a[i] + 1);
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(a[i][j] == 'o') {
                for(int k = 1; k <= 10; k++) visited[k][j] = visited[i][k] = true;
            }
        }
    }
    int res = 20;
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(!visited[i][j]) {
                res = min(res, abs(x - i) + abs(y - j));
            }
        }
    } cout << res;
}