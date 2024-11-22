#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n]; int sum = 0;
    for(int i = 0; i < n; i++) { cin >> a[i]; sum += a[i]; }
    sort(a, a + n); vector<int> v; for(int i = n - 1; i >= 0; i--) {
        if(v.empty() || v.back() != sum - a[i]) v.push_back(sum - a[i]);
    }
    cout << v.size() << '\n';
    for(int const val : v) cout << val << ' ';
}
