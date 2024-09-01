#include <array>
#include <iostream>
#include <optional>
#include <string>
#include <variant>
using namespace std;
optional<string> f(array<int, 3> const &a, int state) {
    static variant<monostate, monostate, string> dp[51][51][51][6] {};
    auto &val = dp[a[0]][a[1]][a[2]][state];
    if(auto const *p = get_if<2>(&val)) return make_optional<string>(*p);
    if(auto const *p = get_if<1>(&val)) return nullopt;
    if(!a[0] && !a[1] && !a[2]) return make_optional<string>(get<2>(val = ""));
    switch(state) {
        case 0:
            if(a[0]) {
                if(auto res = f({a[0] - 1, a[1], a[2]}, 0)) {
                    return make_optional<string>(get<2>(val = 'A' + std::move(*res)));
                }
            }
            if(a[1]) {
                if(auto res = f({a[0], a[1] - 1, a[2]}, 1)) {
                    return make_optional<string>(get<2>(val = 'B' + std::move(*res)));
                }
            }
            if(a[2]) {
                if(auto res = f({a[0], a[1], a[2] - 1}, 2)) {
                    return make_optional<string>(get<2>(val = 'C' + std::move(*res)));
                }
            }
            break;
        case 1:
            if(a[0]) {
                if(auto res = f({a[0] - 1, a[1], a[2]}, 0)) {
                    return make_optional<string>(get<2>(val = 'A' + std::move(*res)));
                }
            }
            if(a[2]) {
                if(auto res = f({a[0], a[1], a[2] - 1}, 2)) {
                    return make_optional<string>(get<2>(val = 'C' + std::move(*res)));
                }
            }
            break;
        case 2:
            if(a[0]) {
                if(auto res = f({a[0] - 1, a[1], a[2]}, 4)) {
                    return make_optional<string>(get<2>(val = 'A' + std::move(*res)));
                }
            }
            if(a[1]) {
                if(auto res = f({a[0], a[1] - 1, a[2]}, 5)) {
                    return make_optional<string>(get<2>(val = 'B' + std::move(*res)));
                }
            }
            break;
        case 3:
            if(a[0]) {
                if(auto res = f({a[0] - 1, a[1], a[2]}, 4)) {
                    return make_optional<string>(get<2>(val = 'A' + std::move(*res)));
                }
            }
            break;
        case 4:
            if(a[0]) {
                if(auto res = f({a[0] - 1, a[1], a[2]}, 0)) {
                    return make_optional<string>(get<2>(val = 'A' + std::move(*res)));
                }
            }
            if(a[1]) {
                if(auto res = f({a[0], a[1] - 1, a[2]}, 1)) {
                    return make_optional<string>(get<2>(val = 'B' + std::move(*res)));
                }
            }
            break;
        case 5:
            if(a[0]) {
                if(auto res = f({a[0] - 1, a[1], a[2]}, 0)) {
                    return make_optional<string>(get<2>(val = 'A' + std::move(*res)));
                }
            }
            break;
        default: __builtin_unreachable();
    }
    val.emplace<1>();
    return nullopt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    array<int, 3> a; a[0] = a[1] = a[2] = 0;
    for(char c : s) a[c - 'A']++;
    if(auto const res = f(a, 0)) cout << *res;
    else cout << -1;
}
