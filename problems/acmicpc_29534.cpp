#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    if(s.size() > n) { cout << "Impossible"; return 0; }
    int res = 0;
    for(char const c : s) res += 1 + static_cast<int>(c - 'a');
    cout << res;
}
