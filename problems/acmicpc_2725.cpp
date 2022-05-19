#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int phi[1001];
    for(int i = 0; i <= 1000; i++) phi[i] = i;
    for(int i = 2; i <= 1000; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= 1000; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    for(int i = 1; i <= 1000; i++) {
        phi[i] += phi[i - 1];
    }
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        cout << ((phi[n] << 1) | 1) << '\n';
    }
}