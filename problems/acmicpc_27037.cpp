#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    set<int> s;
    int cnt = 0;
    while(s.find(n) == s.end()) {
        s.insert(n); cnt++;
        n = (n / 10) % 100;
        n *= n;
    } cout << cnt;
}