#include <iostream>
#include <string>
using namespace std;
static constexpr char const *heart[] = {
        " @@@   @@@ ",
        "@   @ @   @",
        "@    @    @",
        "@         @",
        " @       @ ",
        "  @     @  ",
        "   @   @   ",
        "    @ @    ",
        "     @     "
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string a[9];
    while(n--) {
        for(int i = 0; i < 9; i++) {
            a[i] += heart[i];
        }
        if(n) for(auto & i : a) i += ' ';
    }
    for(int i = 0; i < 9; i++) {
        cout << a[i];
        if(i != 8) cout << '\n';
    }
}