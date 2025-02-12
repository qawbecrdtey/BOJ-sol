#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int x, a, b, c; cin >> x >> a >> b >> c;
    if(a <= x) cout << "Watermelon";
    else if(b <= x) cout << "Pomegranates";
    else if(c <= x) cout << "Nuts";
    else cout << "Nothing";
}
