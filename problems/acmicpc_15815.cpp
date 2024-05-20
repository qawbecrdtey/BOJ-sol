#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace std;
bool is_integer(char c) { return '0' <= c && c <= '9'; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    vector<int> v;
    for(auto c : s) {
        if(is_integer(c)) {
            v.push_back(c - '0');
            continue;
        }
        auto const second = v.back(); v.pop_back();
        auto const first = v.back(); v.pop_back();
        switch(c) {
            case '+': v.push_back(first + second); break;
            case '-': v.push_back(first - second); break;
            case '*': v.push_back(first * second); break;
            case '/': v.push_back(first / second); break;
            default: __builtin_unreachable();
        }
    }
    cout << v.back();
}
