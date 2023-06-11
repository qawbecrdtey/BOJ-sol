#include <iostream>
#include <string>
using namespace std;
bool f(string const &a, string const &b) {
    auto const n = min(a.size(), b.size());
    for(int i = 1; i <= n; i++) {
        bool flag = true;
        for(int j = 0; j < i; j++) {
            if(a[a.size() - i + j] != b[j]) { flag = false; break; }
        }
        if(flag) return true;
    } return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new string[n];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            cnt += (f(a[i], a[j]) || f(a[j], a[i]));
        }
    } cout << cnt;
}