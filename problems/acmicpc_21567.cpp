#include <iostream>
using namespace std;
int main() {
    int xa, xb, xc; cin >> xa >> xb >> xc;
    __int128_t a = xa, b = xb, c = xc;
    a *= b * c;
    int arr[10]{};
    while(a) {
        arr[a % 10]++;
        a /= 10;
    } for(auto i : arr) cout << i << '\n';
}