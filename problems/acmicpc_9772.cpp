#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    double a, b; while(cin >> a >> b) {
        if(a == 0 || b == 0) cout << "AXIS\n";
        else if(a > 0) {
            if(b > 0) cout << "Q1\n";
            else cout << "Q4\n";
        }
        else {
            if(b > 0) cout << "Q2\n";
            else cout << "Q3\n";
        }
        if(a == 0 && b == 0) return 0;
    }
}