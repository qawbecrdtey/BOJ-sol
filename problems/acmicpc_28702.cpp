#include <iostream>
#include <exception>
#include <string>
using namespace std;
string fb(int n) {
    bool const a = !(n % 3);
    bool const b = !(n % 5);
    if(!a && !b) return to_string(n);
    if(!a) return "Buzz";
    if(!b) return "Fizz";
    return "FizzBuzz";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string a, b, c; cin >> a >> b >> c;
    try {
        auto na = stoi(a);
        cout << fb(na + 3);
        return 0;
    } catch (std::exception const &e) {
        try {
            auto nb = stoi(b);
            cout << fb(nb + 2);
            return 0;
        } catch(std::exception const &e) {
            try {
                auto nc = stoi(c);
                cout << fb(nc + 1);
            } catch(std::exception const &e) {
                return 1;
            }
        }
    }
}
