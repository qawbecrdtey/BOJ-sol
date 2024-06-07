#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    string s, t;
    for(int i = 0; i < n; i++) {
        string u; cin >> u; s += u;
    }
    for(int i = 0; i < n; i++) {
        string u; cin >> u; t += u;
    }
    cout << min(stoull(s), stoull(t));
}
