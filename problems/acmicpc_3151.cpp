#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int s[40001]{};
    vector<int> prev;
    long long res = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        res += s[20000 - x];
        for(int val : prev) s[20000 + val + x]++;
        prev.push_back(x);
    }
    cout << res;
}