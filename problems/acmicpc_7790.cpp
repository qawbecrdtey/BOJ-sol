#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int cnt{}; string s; while(getline(cin, s)) {
        for(int i = 0; i < ((int)s.size()) - 3; i++) {
            cnt += (s[i] == 'j' && s[i + 1] == 'o' && s[i + 2] == 'k' && s[i + 3] == 'e');
        }
    } cout << cnt;
}