#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto x = new int[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    auto l = new int[n];
    for(int i = 0; i < n; i++) cin >> l[i];
    auto c = new char*[n];
    for(int i = 0; i < n; i++) { c[i] = new char[2]; cin >> c[i]; }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(abs(x[j] - x[i]) <= l[j] + l[i] && *c[i] != *c[j]) {
                cout << "YES\n" << j + 1 << ' ' << i + 1;
                return 0;
            }
        }
    } cout << "NO";
}