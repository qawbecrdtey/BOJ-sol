#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
char digit(int x) {
    if(x < 10) return x + '0';
    return (x + 'A' - 10);
}
int main() {
    int n, m; string s;
    cin >> n >> m;
    if(!n) {
        cout << "0";
        return 0;
    }
    while(n) {
        s.push_back(digit(n % m));
        n /= m;
    }
    reverse(s.begin(), s.end());
    cout << s;
}