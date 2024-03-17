#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
struct data1 {
    int height;
    int x;
    bool in;
};
struct data2 {
    int height;
    int x;
    bool operator<(data2 const &a) const {
        return x > a.x || (x == a.x && height < a.height);
    }
};
struct result {
    int x;
    int h;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<data1> v1;
    v1.reserve(n << 1);
    for(int i = 0; i < n; i++) {
        int l, h, r; cin >> l >> h >> r;
        v1.push_back({h, l, true});
        v1.push_back({h, r, false});
    }
    sort(v1.begin(), v1.end(), [](data1 const &a, data1 const &b) {
        return a.x < b.x || (a.x == b.x && ((!a.in && b.in) || (a.in == b.in && a.height < b.height)));
    });
    int idx = 0;
    multiset<int> s;
    priority_queue<data2> pq;
    vector<result> res;
    auto const current_height = [&s]() { return s.empty() ? 0 : *s.rbegin(); };
    while(idx < v1.size()) {
        int const x = v1[idx].x;
        int const current_h = current_height();
        while(idx < v1.size() && v1[idx].x == x) {
            if(!v1[idx].in) s.erase(s.find(v1[idx].height));
            else s.insert(v1[idx].height);
            idx++;
        }
        if(auto const h = current_height(); current_h != h) {
            res.push_back({x, h});
        }
    }
    for(auto const [now_x, now_h] : res) {
        cout << now_x << ' ' << now_h << ' ';
    }
}