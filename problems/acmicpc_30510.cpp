#include <array>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    array<ll, 100001> phis{};
    array<bool, 100001> visited{};
    ll p, q; cin >> p >> q;
    ll const den = q / p;
    for(int i = 0; i <= den; i++) {
        phis[i] = i;
        visited[i] = false;
    }
    for(int i = 2; i <= den; i++) {
        if(visited[i]) continue;
        for(int j = i; j <= den; j += i) {
            visited[j] = true;
            phis[j] /= i;
            phis[j] *= i - 1;
        }
    }
    for(int i = 2; i <= den; i++) {
        phis[i] += phis[i - 1];
    }
    cout << 1 + phis[den];
}