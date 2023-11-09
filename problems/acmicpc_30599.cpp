#pragma GCC optimize("O3")
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string f(int n, int sum, int div, int cur, string s) {
    if(n == sum) {
        reverse(s.begin(), s.end());
        return s;
    }
    if(cur == 0) return f(n, sum + 1, div, 0, std::move(s) + '1');
    if(cur == 1) return f(n, sum + 1, div, (cur * 10) % div, std::move(s) + '1');
    return f(n, sum, div, (cur * 10) % div, std::move(s) + '0');
}
inline string f(int n) {
    int sum = n;
    string s;
    while(n % 10 == 0) s += '0', n /= 10;
    while(n % 5 == 0) s += '0', n /= 5;
    while(n % 2 == 0) s += '0', n /= 2;
    return f(sum, 0, n, 1, "") + s;
}
int main() { int n; cin >> n; cout << f(n); }