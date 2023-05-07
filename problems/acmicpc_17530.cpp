#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) if(a[0] < a[i]) { cout << "N"; return 0; } cout << "S";
}