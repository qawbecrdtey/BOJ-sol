#include <algorithm>
#include <iostream>
using namespace std;
struct info {
    int x, y;
    char c;
    bool operator<(info const &i) const {
        auto const effx = eff(*this);
        auto const effy = eff(i);
        return effx.first * effy.second < effx.second * effy.first;
    }
    static pair<int, int> eff(info const &i) {
        return {i.y * 10, i.x * 10 - ((i.x >= 500) ? 500 : 0)};
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    info a[3]; for(auto &i : a) cin >> i.x >> i.y;
    a[0].c = 'S', a[1].c = 'N', a[2].c = 'U';
    cout << max_element(a, a + 3)->c;
}