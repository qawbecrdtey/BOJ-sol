#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s, t; cin >> n >> s >> t;
    auto const a = new int[n];
    auto const b = new int[n];
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }
    auto const dp = new array<tuple<int, int, int, int>, 10>[n]; // idx, offset
    for(int i = 0; i < n; i++) fill(dp[i].begin(), dp[i].end(), make_tuple(numeric_limits<int>::max() >> 3, -1, -1, -1));
    for(int i = 0; i < 10; i++) { // turn right
        auto const left = (10 + b[0] - a[0] + i) % 10;
        auto const off = left;
        dp[0][off] = {i + left, -1, i, left};
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 10; j++) { // previous offset
            for(int k = 0; k < 10; k++) { // turn right
                auto const left = (20 + b[i] - (a[i] + j) + k) % 10;
                auto const off = (left + j) % 10;
                auto const val = get<0>(dp[i - 1][j]) + k + left;
                if(get<0>(dp[i][off]) < val) continue;
                dp[i][off] = {val, j, k, left};
            }
        }
    }
    auto it = min_element(dp[n - 1].begin(), dp[n - 1].end(), [](auto const &a, auto const &b) { return get<0>(a) < get<0>(b); });
    cout << get<0>(*it);
    int idx = n;
    while(true) {
        if(get<2>(*it)) cout << '\n' << idx << ' ' << -get<2>(*it);
        if(get<3>(*it)) cout << '\n' << idx << ' ' << get<3>(*it);
        if(get<1>(*it) == -1) break;
        it = std::next(dp[--idx - 1].begin(), get<1>(*it));
    }
}
