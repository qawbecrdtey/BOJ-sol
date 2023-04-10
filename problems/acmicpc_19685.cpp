#include <iostream>
#include <string>
using namespace std;
inline bool is_palindrome(long long n) {
    auto const x = to_string(n);
    for(int i = 0; i < x.size() / 2; i++) {
        if(x[i] != x[x.size() - i - 1]) return false;
    } return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long a, b; cin >> a >> b;
    while(a <= b) {
        if(is_palindrome(a)) cout << "Palindrome!\n";
        else cout << a << '\n';
        a++;
    }
}