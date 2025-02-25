#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
string square_root(ll n) {
    vector<ll> one;
    ll two = 1;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            one.push_back(i);
            n /= i;
        }
        while(one.size() > 1 && one[one.size() - 1] == one[one.size() - 2]) {
            two *= one.back();
            one.pop_back(); one.pop_back();
        }
    }
    if(n != 1) one.push_back(n);
    if(one.empty()) return to_string(two);
    ll res = 1;
    for(auto const p : one) res *= p;
    if(two == 1) return "\\sqrt{" + to_string(res) + "}";
    return to_string(two) + " \\cdot \\sqrt{" + to_string(res) + "}";
}
string make1(string const &b, string const &c) {
    auto const B = stoll(b);
    auto const C = stoll(c);
    auto const A = C * C - B * B;
    return square_root(A);
}
string make2(string const &a, string const &b) {
    auto const A = stoll(a);
    auto const B = stoll(b);
    auto const C = A * A + B * B;
    return square_root(C);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string a, b, c; cin >> a >> b >> c;
    if(a == "?") {
        cout << make1(b, c);
        return 0;
    }
    if(b == "?") {
        cout << make1(a, c);
        return 0;
    }
    cout << make2(a, b);
}
