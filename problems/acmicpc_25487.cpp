#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        cout << *min_element(a, a + 3) << '\n';
    }
}