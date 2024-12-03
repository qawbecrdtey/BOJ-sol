#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a[4]; cin >> n >> a[0] >> a[1] >> a[2] >> a[3];
    auto s = new char[n + 1]; cin >> s;
    if(s[0] != 'a' || s[n - 1] != 'a') goto NO;
    for(int i = 0; i < n; i++) {
        if(!a[s[i] - 'a']) goto NO;
        if(i && s[i] == s[i - 1]) goto NO;
        a[s[i] - 'a']--;
    }
    cout << "Yes";
    return 0;
NO: cout << "No";
}
