#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int k = 0, p = 0;
    for(char const c : s) {
        if(c == 'K') {
            k++;
            if(p) p--;
        }
        else if(c == 'P') {
            p++;
            if(k) k--;
        }
        else __builtin_unreachable();
    }
    cout << k + p;
}
