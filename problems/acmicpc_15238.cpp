#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    int a[26]{}; for(char c : s) a[c - 'a']++;
    auto const i = max_element(a, a + 26) - a;
    cout << static_cast<char>(i + 'a') << ' ' << a[i];
}
