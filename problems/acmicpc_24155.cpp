#include <algorithm>
#include <iostream>
using namespace std;
struct info {
    int idx;
    int score;
    int rank;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new info[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].score; a[i].idx = i;
    }
    sort(a, a + n, [](info const &a, info const &b) {
        return a.score > b.score;
    });
    int rank = 1, cnt = 1;
    a[0].rank = 1;
    for(int i = 1; i < n; i++) {
        if(a[i - 1].score != a[i].score) { rank += cnt; cnt = 1; }
        else cnt++;
        a[i].rank = rank;
    }
    sort(a, a + n, [](info const &a, info const &b) {
        return a.idx < b.idx;
    });
    for(int i = 0; i < n; i++) {
        cout << a[i].rank << '\n';
    }
}
