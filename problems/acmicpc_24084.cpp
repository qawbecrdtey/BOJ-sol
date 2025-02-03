#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    for(int i = 1; i < n; i++) {
        if(s[i] == 'J') cout << s[i - 1] << '\n';
    }
}
