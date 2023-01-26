#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string t; while(cin >> t) {
        if(t == "#") return 0;
        int a{}, n{}, y{};
        for(char c : t) {
            a += (c == 'A');
            n += (c == 'N');
            y += (c == 'Y');
        }
        if(a >= (t.size() + 1) / 2) cout << "need quorum\n";
        else if(y > n) cout << "yes\n";
        else if(y < n) cout << "no\n";
        else cout << "tie\n";
    }
}