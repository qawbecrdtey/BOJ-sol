#include <iostream>
using namespace std;
int count(int *const a, int const n, int i) {
    if(i == n) return 0;
    if(a[i - 1] > a[i]) {
        int j = i - 1;
        int cnt = 0;
        while(j >= 0 && a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            j--;
            cnt++;
        }
        return cnt + count(a, n, i + 1);
    }
    return count(a, n, i + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    auto b = new int[n];
    for(int i = 0; i < n; i++) { cin >> a[i]; b[n - i - 1] = a[i]; }
    cout << min(count(a, n, 1), 1 + count(b, n, 1));
}
