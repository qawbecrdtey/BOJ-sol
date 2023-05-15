#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b, c, d; while(cin >> a >> b >> c >> d) {
        if(!a && !b && !c && !d) return 0;
        if(a == c && b == d) { cout << "0\n"; continue; }
        if(a == c || b == d || a + b == c + d || a - b == c - d) { cout << "1\n"; continue; }
        cout << "2\n";
    }
}