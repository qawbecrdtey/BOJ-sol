#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    char a[5][3]; for(auto &now : a) cin >> now;
    map<char, int> m;
    for(auto &now : a) m[*now]++;
    int r = 0; for(auto [c, v] : m) r = max(r, v); cout << r;
}