#include <iostream>
using namespace std;
int main() {
    int a[3], b[3]; for(int &i : a) cin >> i; for(int &i : b) cin >> i;
    int const x = a[0] * 3 + a[1] * 20 + a[2] * 120;
    int const y = b[0] * 3 + b[1] * 20 + b[2] * 120;
    if(x > y) cout << "Max";
    else if(x < y) cout << "Mel";
    else cout << "Draw";
}