#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; int m = 300;
    string t; int n; while(cin >> t >> n) {
        if(m > n) s = std::move(t), m = n;
    } cout << s;
}