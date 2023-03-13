#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    int res{}, cnt{};
    for(char c : s) {
        if(c == '0') {
            if(cnt) {
                res++; cnt--;
            }
        }
        else {
            cnt = 2;
            res++;
        }
    } cout << res;
}