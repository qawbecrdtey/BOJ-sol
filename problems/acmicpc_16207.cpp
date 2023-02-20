#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new long long[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, [](long long a, long long b) { return a > b; });
    int i = 1;
    vector<long long> v;
    while(i < n) {
        if(a[i - 1] - a[i] <= 1) {
            v.push_back(a[i]);
            i += 2;
            continue;
        } i++;
    } long long res{};
    for(i = 1; i < v.size(); i += 2) {
        res += v[i - 1] * v[i];
    } cout << res;
}