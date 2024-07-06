#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
template<typename Iterator>
int mex(Iterator l, Iterator r) {
    assert(l <= r);
    set<int> s;
    for(auto p = l; p != r; ++p) {
        s.insert(*p);
    }
    int res = 0;
    while(!s.empty()) {
        auto it = s.begin();
        if(res == *it) {
            s.erase(it);
            res++;
        }
        else break;
    }
    return res;
}
template<typename Iterator>
int contains_equal_range(Iterator ait, Iterator bit, int length) {
    for(int i = 0; ait + i + 1 < bit; i++) {
        for(int j = 0; j < length; j++) {
            if(*(ait + i + j) != *(bit + j)) goto NO;
        }
        return i;
        NO:
        continue;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int m, k; cin >> m >> k;
    auto a = new int[k];
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    vector<int> state;
    for(int i = 0; i <= a[k - 1]; i++) {
        vector<int> next;
        for(int j = 0; a[j] <= i && j < k; j++) {
            next.push_back(state[i - a[j]]);
        }
        state.push_back(mex(next.begin(), next.end()));
    }
    int cur_i = a[k - 1] + 1;
    int off;
    while((off = contains_equal_range(state.begin(), state.end() - a[k - 1] - 1, a[k - 1])) == -1) {
        vector<int> next;
        for(int j = 0; j < k; j++) {
            next.push_back(state[cur_i - a[j]]);
        }
        state.push_back(mex(next.begin(), next.end()));
        cur_i++;
    }

    if(m < state.size()) {
        int res = 0;
        for(int i = 1; i <= m; i++) {
            res += !state[i];
        }
        cout << res;
        return 0;
    }
    int res = 0;
    for(int i = 1; i <= off; i++) {
        res += !state[i];
    }
    int cyc = 0;

    for(int i = off + 1; i <= state.size() - a[k - 1] - 1; i++) {
        cyc += !state[i];
    }

    m -= off;
    res += cyc * (m / (static_cast<int>(state.size()) - a[k - 1] - 1 - off));
    m %= (static_cast<int>(state.size()) - a[k - 1] - 1 - off);
    for(int i = 1; i <= m; i++) {
        res += !state[off + i];
    }
    cout << res;
}
