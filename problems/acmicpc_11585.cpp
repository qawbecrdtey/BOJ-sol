#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<char> v1, v2; v1.reserve(n << 1); v2.reserve(n);
    for(int i = 0; i < n; i++) { char c[2]; cin >> c; v1.push_back(c[0]); }
    for(int i = 0; i < n; i++) { char c[2]; cin >> c; v2.push_back(c[0]); }
    for(int i = 0; i < n - 1; i++) v1.push_back(v1[i]);
    auto pi = new int[n]();
    for(int i = 1, j = 0; i < n; i++) {
        while(j && v2[i] != v2[j]) j = pi[j - 1];
        if(v2[i] == v2[j]) pi[i] = ++j;
    }
    int cnt = 0;
    for(int i = 0, j = 0; i < (n << 1) - 1; i++) {
        while(j && v1[i] != v2[j]) j = pi[j - 1];
        if(v1[i] == v2[j]) {
            if(j == n - 1) cnt++, j = pi[j];
            else j++;
        }
    }
    int g = gcd(cnt, n);
    cout << cnt / g << '/' << n / g;
}