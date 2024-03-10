#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
pair<ll, ll> dp(vector<pair<ll, ll>> const *const v, ll const now, ll const prev) noexcept {
    ll not_ending_at_root = 0;
    ll ending_at_root = 0;
    ll sum = 0;
    ll sq_sum = 0;
    for(auto const [next, cost] : v[now]) {
        if(next == prev) continue;
        auto [next_not_ending_at_root, next_ending_at_root] = dp(v, next, now);
        ll const val = cost * (next_ending_at_root + 1) % M;
        not_ending_at_root = ((not_ending_at_root + next_not_ending_at_root) % M + next_ending_at_root) % M;
        ending_at_root = (ending_at_root + val) % M;
        sum = (sum + val) % M;
        sq_sum = (sq_sum + (val * val) % M) % M;
    }
    ll add = (((sum * sum) % M - sq_sum) % M + M) % M;
    if(add & 1) add = (add + M) / 2;
    else add /= 2;
    not_ending_at_root = (not_ending_at_root + add) % M;

    return {not_ending_at_root, ending_at_root};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const v = new vector<pair<ll, ll>>[n + 1];
    for(int i = 1; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        v[x].emplace_back(y, z);
        v[y].emplace_back(x, z);
    }
    auto const [not_ending_at_root, ending_at_root] = dp(v, 1, -1);
    cout << (not_ending_at_root + ending_at_root) % M;
}