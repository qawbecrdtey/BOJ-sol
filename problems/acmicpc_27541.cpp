#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    for(int i = 0; i < n - 1; i++) cout << s[i];
    if(s[n - 1] != 'G') cout << s[n - 1] << 'G';
}