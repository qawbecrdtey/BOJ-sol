#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s;
    while(true) {
        cin >> s;
        if(s == "END") return 0;
        int cnt = 1;
        while(s != "1") s = to_string(s.size()), cnt++;
        cout << cnt << '\n';
    }
}