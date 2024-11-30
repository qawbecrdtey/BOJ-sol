#include <array>
#include <iostream>
using namespace std;
static std::array<int, 1000001> sum() {
    std::array<int, 1000001> arr{{}};
    for(int i = 1; i <= 1000000; i++) {
        for(int j = i; j <= 1000000; j += i) {
            arr[j] += i;
        }
    }
    return arr;
}
static char const *f(int n, int m) {
    n <<= 1;
    if(n == m) return "perfect\n";
    if(n < m) return "abundant\n";
    return "deficient\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    static auto arr = sum();
    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        cout << "n = " << n << ", arr[n] = " << arr[n] << '\n';
        cout << f(n, arr[n]);
    }
}
