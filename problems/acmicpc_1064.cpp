#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
using namespace std;
inline double dist(pair<int, int> const &a, pair<int, int> const &b) {
    return sqrt(static_cast<double>((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)));
}
int main() {
    pair<int, int> a[3];
    for(auto &now : a) cin >> now.first >> now.second;
    sort(a, a + 3);
    pair<int, int> b[2] = { { a[1].first - a[0].first, a[1].second - a[0].second }, { a[2].first - a[1].first, a[2].second - a[1].second } };
    for(auto &now : b) {
        int g = gcd(now.first, now.second);
        now.first /= g; now.second /= g;
    }
    if(b[0].first == b[1].first && b[0].second == b[1].second) {
        printf("-1"); return 0;
    }
    double d[3];
    d[0] = dist(a[0], a[1]) + dist(a[0], a[2]);
    d[1] = dist(a[1], a[0]) + dist(a[1], a[2]);
    d[2] = dist(a[2], a[0]) + dist(a[2], a[1]);
    for(auto &now : d) now *= 2;
    sort(d, d + 3);
    printf("%.12f", d[2] - d[0]);
}