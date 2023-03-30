#include <iostream>
#include <string>
using namespace std;
struct info {
    string _1, _2, _3;
    bool operator==(info const &s) const {
        return (_1 == s._1 || s._1 == "-") && (_2 == s._2 || s._2 == "-") && (_3 == s._3 || s._3 == "-");
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new info[n];
    for(int i = 0; i < n; i++) cin >> a[i]._1 >> a[i]._2 >> a[i]._3;
    while(m--) {
        int cnt = 0;
        string _1, _2, _3; cin >> _1 >> _2 >> _3;
        info const val{std::move(_1), std::move(_2), std::move(_3)};
        for(int i = 0; i < n; i++) {
            cnt += (a[i] == val);
        } cout << cnt << '\n';
    }
}