#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto yonsei = "YONSEI", korea = "KOREA";
    auto const yonsei_size = 6, korea_size = 5;
    string s; cin >> s;
    int y = 0, k = 0;
    for(int i = 0; i < s.size(); i++) {
        if(y == yonsei_size) {
            cout << yonsei;
            return 0;
        }
        if(k == korea_size) {
            cout << korea;
            return 0;
        }
        if(s[i] == yonsei[y]) y++;
        if(s[i] == korea[k]) k++;
    }
}