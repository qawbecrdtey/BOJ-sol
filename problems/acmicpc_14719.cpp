#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int m, n; cin >> m >> n;
    stack<pair<int, int>> s;
    long long sum{};
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(s.empty() || s.top().first > x) {
            s.emplace(x, i);
            continue;
        }
        if(s.top().first == x) {
            s.top().second = i;
            continue;
        }
        int prev = s.top().first;
        s.pop();
        while(!s.empty()) {
            sum += (i - s.top().second - 1) * (min(s.top().first, x) - prev);
            if(s.top().first >= x) break;
            prev = s.top().first;
            s.pop();
        }
        if(s.empty() || s.top().first > x) s.emplace(x, i);
        else if(s.top().first == x) s.top().second = i;
        else __builtin_unreachable();
    } cout << sum;
}