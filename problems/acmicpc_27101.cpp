#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i][i] != 0) {
            cout << 1;
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(a[i][j] <= 0) {
                cout << 2;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i][j] != a[j][i]) {
                cout << 3;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[i][j] + a[j][k] < a[i][k]) {
                    cout << 4;
                    return 0;
                }
            }
        }
    }
    cout << 0;
}