#include <iostream>
#include <vector>
using namespace std;
void f(int left, int limit, vector<int> &v) {
    if(left == 0) {
        for(int now : v) cout << now << ' '; cout << '\n';
        return;
    }
    for(int i = min(limit, left); i; i--) {
        v.push_back(i);
        f(left - i, i, v);
        v.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v;
    f(n, n, v);
}