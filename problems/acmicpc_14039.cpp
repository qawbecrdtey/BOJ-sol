#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[4][4];
    for(auto &i : a) {
        for(int &j : i) {
            cin >> j;
        }
    }
    int const sum = a[0][0] + a[0][1] + a[0][2] + a[0][3];
    for(int i = 0; i < 4; i++) {
        if(a[i][0] + a[i][1] + a[i][2] + a[i][3] != sum) goto NO;
        if(a[0][i] + a[1][i] + a[2][i] + a[3][i] != sum) goto NO;
    }
    goto YES;
NO: cout << "not ";
YES:cout << "magic";
}