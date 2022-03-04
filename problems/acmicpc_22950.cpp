#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; string s; cin >> n >> s; cin >> n;
    while(n && !s.empty()) {
        if(s.back() != '0') break;
        s.pop_back();
        n--;
    }
    if(s.empty() || !n) {
        cout << "YES";
    } else cout << "NO";
}