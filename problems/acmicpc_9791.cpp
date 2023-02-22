#include <iostream>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; while(cin >> s) {
        if(s == "0") return 0;
        bool start = true;
        char now;
        int cnt;
        for(char c : s) {
            if(start) {
                cnt = 1;
                now = c;
                start = false;
            }
            else if(c != now) {
                cout << cnt << now;
                cnt = 1;
                now = c;
            }
            else cnt++;
        }
        cout << cnt << now << '\n';
    }
}