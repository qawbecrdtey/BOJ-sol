#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if(a == 1) cout << 1;
    else if(a == 10) cout << 2;
    else if(a == 100) cout << 3;
    else if(a == 1000) cout << 4;
    else cout << (long long)(ceil(logl(a) / logl(10) * b));
}