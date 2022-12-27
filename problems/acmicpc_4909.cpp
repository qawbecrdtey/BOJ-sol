#include <algorithm>
#include <iostream>
using namespace std;
char const *point(int x) {
    switch(x % 4) {
        case 0: return "";
        case 1: return ".25";
        case 2: return ".5";
        case 3: return ".75";
        default: __builtin_unreachable();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[6]{};
    while(true) {
        for(auto &i : a) cin >> i;
        if(all_of(a, a + 6, [](int x) { return x == 0; })) return 0;
        sort(a, a + 6);
        cout << (a[1] + a[2] + a[3] + a[4]) / 4 << point(a[1] + a[2] + a[3] + a[4]) << '\n';
    }
}