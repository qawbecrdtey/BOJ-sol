#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    pair<string, int> a[7];
    for(auto &[s, i] : a) cin >> s >> i;
    cout << max_element(a, a + 7, [](auto a, auto b) { return a.second < b.second; })->first;
}
