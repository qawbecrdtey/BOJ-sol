#include <iostream>
using namespace std;
int main() {
    long double a, b; cin >> a >> b; cout.precision(12); cout << fixed << 100 * b / (100 - b);
}
