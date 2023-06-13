#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int b[3]; pair<int, string> s[3];
    for(int i = 0; i < 3; i++) cin >> s[i].first >> b[i] >> s[i].second;
    int x[3] {b[0] % 100, b[1] % 100, b[2] % 100};
    sort(x, x + 3);
    cout << x[0] << x[1] << x[2] << '\n';
    sort(s, s + 3, [](auto a, auto b) { return a.first < b.first; });
    cout << s[2].second[0] << s[1].second[0] << s[0].second[0];
}