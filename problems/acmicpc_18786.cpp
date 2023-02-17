#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<int, int>[n];
    int res = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                if(a[i].first == a[j].first && a[i].second == a[k].second) res = max(res, abs(a[i].second - a[j].second) * abs(a[i].first - a[k].first));
                if(a[i].second == a[j].second && a[i].first == a[k].first) res = max(res, abs(a[i].first - a[j].first) * abs(a[i].second - a[k].second));
                if(a[j].first == a[i].first && a[j].second == a[k].second) res = max(res, abs(a[j].second - a[i].second) * abs(a[j].first - a[k].first));
                if(a[j].second == a[i].second && a[j].first == a[k].first) res = max(res, abs(a[j].first - a[i].first) * abs(a[j].second - a[k].second));
                if(a[k].first == a[j].first && a[k].second == a[i].second) res = max(res, abs(a[k].second - a[j].second) * abs(a[k].first - a[i].first));
                if(a[k].second == a[j].second && a[k].first == a[i].first) res = max(res, abs(a[k].first - a[j].first) * abs(a[k].second - a[i].second));
            }
        }
    } cout << res;
}