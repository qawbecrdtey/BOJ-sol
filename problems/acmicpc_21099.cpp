#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long n; cin >> n;
    if(n * (n - 1) > (1 << 18)) {
        cout << "Yes"; return 0;
    }
    auto *a = new int[n];
    vector<int> v;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
        for(long long j = 0; j < i; j++) {
            v.push_back(a[i] ^ a[j]);
        }
    } sort(v.begin(), v.end());
    for(long long i = 1; i < v.size(); i++) {
        if(v[i - 1] == v[i]) {
            cout << "Yes";
            return 0;
        }
    } cout << "No";
}