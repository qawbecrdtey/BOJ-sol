#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    set<pair<int, int>> s;
    s.insert(make_pair(m, k));
    int day = 0;
    while(!s.empty() && day < n) {
        set<pair<int, int>> t;
        int x; cin >> x;
        for(auto const [milk, biscuts] : s) {
            if(x <= milk) t.insert(make_pair(milk - x, biscuts));
            if(biscuts) t.insert(make_pair(milk, biscuts - 1));
        }
        if(t.empty()) break;
        s = std::move(t);
        day++;
    }
    cout << day;
}
