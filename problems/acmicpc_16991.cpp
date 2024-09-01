#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>
using namespace std;
double sq(double const d) noexcept { return d * d; }
double d(pair<double, double> const &a, pair<double, double> const &b) noexcept {
    return sqrt(sq(a.first - b.first) + sq(a.second - b.second));
}
double min_dist(int const n, int const s, double const *const *const dist) {
    auto const dp = make_unique<unique_ptr<double[]>[]>(1 << n);
    for(int i = 0; i < (1 << n); i++) {
        dp[i] = make_unique<double[]>(n);
        fill(dp[i].get(), dp[i].get() + n, numeric_limits<double>::max());
    }
    vector<tuple<int, int, double>> st;
    st.emplace_back(1 << s, s, 0.0);
    while(!st.empty()) {
        auto const [now, now_idx, now_dist] = st.back();
        st.pop_back();
        if(dp[now][now_idx] < now_dist) continue;
        dp[now][now_idx] = now_dist;
        for(int i = 0; i < n; i++) {
            if((now >> i) & 1) continue;
            st.emplace_back(now | (1 << i), i, now_dist + dist[now_idx][i]);
        }
    }
    double res = numeric_limits<double>::max();
    for(int i = 1; i < n; i++) {
        res = min(res, dp[(1 << n) - 1][i] + dist[s][i]);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<double, double>[n];
    auto dist = new double*[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        dist[i] = new double[n];
        for(int j = 0; j < i; j++) {
            dist[i][j] = dist[j][i] = d(a[j], a[i]);
        }
        dist[i][i] = 0;
    }
    cout.precision(12);
    cout << fixed << min_dist(n, 0, dist);
}
