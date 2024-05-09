#include <iostream>
#include <numeric>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    set<pair<int, int>> s;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int x = a[i].first - a[j].first;
            int y = a[i].second - a[j].second;
            if(!x) y = 1;
            else if(!y) x = 1;
            else if(x < 0) x = -x, y = -y;
            int const g = gcd(x, y);
            if(g) x /= g, y /= g;
            s.insert({x, y});
        }
    }
    cout << s.size();
}
