#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    if(n == 2 && k == 1) cout << "1 2";
    else if(n == 1) for(int i = 0; i < k; i++) cout << "1 ";
    else cout << -1;
}
