#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto a = new string*[10];
    for(int i = 0; i < 10; i++) {
        a[i] = new string[10];
        for(int j = 0; j < 10; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 10; i++) {
        int j;
        for(j = 1; j < 10; j++) {
            if(a[i][0] != a[i][j]) break;
        }
        if(j == 10) { cout << 1; return 0; }
    }
    for(int i = 0; i < 10; i++) {
        int j;
        for(j = 1; j < 10; j++) {
            if(a[0][i] != a[j][i]) break;
        }
        if(j == 10) { cout << 1; return 0; }
    }
    cout << 0;
}
