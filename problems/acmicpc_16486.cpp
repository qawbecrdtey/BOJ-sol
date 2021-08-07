#include <iostream>
using namespace std;
int main() {
    cout.precision(6);
    cout << fixed;
    double d, r;
    cin >> d >> r;
    cout << d * 2 + r * 3.141592 * 2;
}