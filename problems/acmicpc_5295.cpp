#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            int const d = a[j] - a[i];
            if(binary_search(a + j + 1, a + n, a[j] + d)) {
                cout << "Sequence is not 3-free. Witness: " << a[i] << ',' << a[j] << ',' << a[j] + d << '.';
                return 0;
            }
        }
    }
    cout << "Sequence is 3-free.";
}