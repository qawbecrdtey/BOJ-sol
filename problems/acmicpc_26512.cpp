#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto const print = [](int n) {
        cout << n << " = ";
        for(int i = 7; i >= 0; i--) {
            cout << ((n >> i) & 1);
        } cout << '\n';
    };
    int a, b; while(cin >> a >> b) {
        if(!a && !b) return 0;
        print(a);
        print(b);
        print(-a);
        print(-b);
        print(a - b);
        cout << '\n';
    }
}