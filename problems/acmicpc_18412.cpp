#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b; cin >> n >> a >> b; a--;
    string s; cin >> s;
    reverse(s.begin() + a, s.begin() + b);
    cout << s;
}