#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
// bool zigzag(int const *const begin, int const *const end) {
//     if(begin == end || begin + 1 == end) return true;
//     for(int i = 1; i < end - begin - 1; i++) {
//         if((begin[i] - begin[i - 1]) * (begin[i] - begin[i + 1]) < 0) return false;
//     }
//     return true;
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr); cout.tie(nullptr);
//     int n; cin >> n;
//     auto a = new int[n];
//     for(int i = 0; i < n; i++) a[i] = i;
//     int cnt = 0;
//     do {
//         if(!zigzag(a, a + n)) continue;
//         for(int i = 0; i < n; i++) cout << a[i] << ' ';
//         cout << '\n';
//         cnt++;
//     } while(next_permutation(a, a + n));
//     cout << "total count: " << cnt << '\n';
//     delete[] a;
// }
static constexpr int M = 1000000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; if(n == 1) { cout << 1; return 0; }
    auto a = new int*[n + 2];
    for(int i = 1; i < n + 2; i++) {
        a[i] = new int[i];
        if(i == 1) {
            a[i][0] = 1;
            continue;
        }
        for(int j = 0; j < i - 1; j++) {
            for(int k = j; k < i - 1; k++) {
                a[i][j] += a[i - 1][i - 2 - k];
            }
            a[i][j] %= M;
        }
        a[i][i - 1] = 0;
    }
    cout << (a[n + 1][0] * 2) % M;
}
