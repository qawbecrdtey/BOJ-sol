#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    if(n < m) { cout << "NE"; return 0; }
    auto a = new int[n];
    int sum = 0;
    for(int i = 0; i < m; i++) { cin >> a[i]; a[i] /= 4; if(a[i] == 0) { cout << "NE"; return 0; } sum += a[i]; }
    if(sum < n) { cout << "NE"; return 0; }
    cout << "DA";
}