#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; auto const a = new int[t];
    for(int i = 0; i < t; i++) cin >> a[i];
    int const m = *max_element(a, a + t);
    auto const phi = new int[m + 1]; phi[0] = phi[1] = 1;
    auto const visited = new bool[m + 1]();
    for(int i = 2; i <= m; i++) phi[i] = i;
    for(int i = 2; i <= m; i++) {
        if(!visited[i]) {
            phi[i]--;
            for(int j = (i << 1); j <= m; j += i) {
                phi[j] /= i;
                phi[j] *= i - 1;
                visited[j] = true;
            }
        }
    }
    for(int i = 1; i <= m; i++) phi[i] += phi[i - 1];
    for(int i = 0; i < t; i++) {
        cout << phi[a[i]] << '\n';
    }
}