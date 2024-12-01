#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s; __int128_t val = 16;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != 'E' && s[i] != 'O') goto INVALID;
        if(!i) continue;
        if(s[i] == 'O' && s[i - 1] == 'O') goto INVALID;
    }
    if(s.back() != 'O') goto INVALID;
    while(true) {
        __int128_t cur = val;
        for(int i = static_cast<int>(s.size()) - 1; i >= 0; i--) {
            if(s[i] == 'O') {
                if((cur - 1) % 3) goto NEXT;
                cur = (cur - 1) / 3;
            }
            else if(s[i] == 'E') {
                cur <<= 1;
            }
        }
        cout << static_cast<long long>(cur);
        return 0;
NEXT:   val <<= 1;
    }
INVALID:
    cout << "INVALID";
}
