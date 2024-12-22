#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s; int cnt = 0; for(char const c : s) cnt += c == ',';
    if(cnt == 0) { cout << (s.size() == 4); return 0; }
    int a[16]{};
    for(int i = 2; i < 16; i++) {
        a[i] = i - 1;
        for(int j = 0; j < i; j++) {
            a[i] += a[j];
        }
        if(cnt == a[i]) { cout << i; return 0; }
    }
    return 0;
}
