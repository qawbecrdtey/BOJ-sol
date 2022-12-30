#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; for(int i = 1; i <= n; i++) {
        cout << i << ' '; if(i % 6 == 0 || i == n) cout << "Go! ";
    }
}