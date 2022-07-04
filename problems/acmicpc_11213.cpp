#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a[7];
    for(int i = 0; i < n; i++) {
        int x; cin >> x; a[x].push_back(i);
    } int res = 0;
    for(int i = 1; i <= 6; i++) {
        if(a[i].size() != 1) continue;
        res = a[i][0] + 1;
    } if(!res) cout << "none";
    else cout << res;
}