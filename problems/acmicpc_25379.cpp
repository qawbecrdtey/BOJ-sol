#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i] &= 1; cnt += a[i];
    }
    int even{}, odd{};
    long long evenres{}, oddres{};
    for(int i = 0; i < n; i++) {
        evenres += (!(a[i] & 1)) * (i - even);
        oddres += (a[i] & 1) * (i - odd);
        even += !(a[i] & 1);
        odd += (a[i] & 1);
    } cout << min(evenres, oddres);
}