#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    bool inside = true;
    int cnt = 0;
    int res = 0;
    for(int i = 1; i < s.size(); i++) {
        if(!inside) inside = true;
        else if(!cnt && s[i] == ')') {
            inside = false;
            res += (s[i - 1] != '(');
        }
        else if(s[i] == '(') cnt++;
        else if(s[i] == ')') {
            if(s[i - 1] == '(') res += cnt;
            else res++;
            cnt--;
        }
    } cout << res;
}