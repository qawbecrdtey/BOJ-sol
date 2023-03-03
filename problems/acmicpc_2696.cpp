#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n; cout << (n + 1) / 2 << '\n';
        priority_queue<ll> pql, pqr;
        vector<ll> res; res.reserve((n + 1) / 2);
        ll x; cin >> x; pql.push(x);
        for(int i = 1; i < (n + 1) / 2; i++) {
            assert(pqr.empty() || pql.top() <= -pqr.top());
            res.push_back(pql.top());
            cin >> x;
            if(pql.top() > x) {
                pql.push(x);
                x = pql.top();
                pql.pop();
            }
            pqr.push(-x);
            cin >> x;
            if(-pqr.top() < x) {
                pqr.push(-x);
                x = -pqr.top();
                pqr.pop();
            }
            pql.push(x);
        }
        res.push_back(pql.top());
        assert(res.size() == (n + 1) / 2);
        for(int i = 0; i < (n + 1) / 2; i++) {
            cout << res[i] << ' ';
            if(i % 10 == 9 && i != (n - 1) / 2) {
                cout << '\n';
            }
        } cout << '\n';
    }
}