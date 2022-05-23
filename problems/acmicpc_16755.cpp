#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int idx = 0, cnt = 0;
    string t("HONI");
    for(char c : s) {
        if(t[idx] == c) {
            idx++;
            if(idx == 4) idx = 0, cnt++;
        }
    } cout << cnt;
}