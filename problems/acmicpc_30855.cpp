#include <iostream>
#include <numeric>
#include <vector>
enum type {
    Char,
    Num,
    Expr
};
struct S {
    type t;
    void *content; // length 3 array if Expr
};
using namespace std;
inline bool is_digit(char const c) { return '0' <= c && c <= '9'; }
using ll = long long;
pair<ll, ll> compute(S const *s) {
    if(s->t == Num) {
        return { *static_cast<int *>(s->content), 1 };
    }
    auto const v1 = compute(&static_cast<S*>(s->content)[0]);
    auto const v2 = compute(&static_cast<S*>(s->content)[1]);
    auto const v3 = compute(&static_cast<S*>(s->content)[2]);
    auto const g1 = gcd(v2.first, v3.first);
    auto const g2 = gcd(v2.second, v3.second);
    pair<ll, ll> const v = { v2.first / g1 * v3.second / g2, v2.second / g2 * v3.first / g1 };
    auto const g = gcd(v1.first * v.second + v.first * v1.second, v1.second * v.second);
    return { (v1.first * v.second + v.first * v1.second) / g, v1.second * v.second / g };
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<S> v;
    for(int i = 0; i < n; i++) {
        char c[2];
        cin >> c;
        if(is_digit(*c)) {
            v.push_back({ Num, new int(stoi(c)) });
        }
        else {
            if(*c == ')') {
                if(v.size() < 4) {
                    cout << "-1";
                    return 0;
                }
                auto first = v[v.size() - 4];
                auto second = v[v.size() - 3];
                auto third = v[v.size() - 2];
                auto fourth = v[v.size() - 1];
                v.resize(v.size() - 4);
                if(first.t != Char || *static_cast<char*>(first.content) != '(') {
                    cout << "-1";
                    return 0;
                }
                if(second.t == Char || third.t == Char || fourth.t == Char) {
                    cout << "-1";
                    return 0;
                }
                delete static_cast<char*>(first.content);
                v.push_back({ Expr, new S[3]{ second, third, fourth } });
                continue;
            }
            v.push_back({ Char, new char(*c) });
        }
    }
    if(v.size() != 1 || v[0].t != Expr) {
        cout << "-1";
        return 0;
    }
    auto const [num, den] = compute(&v[0]);
    cout << num << ' ' << den;
}