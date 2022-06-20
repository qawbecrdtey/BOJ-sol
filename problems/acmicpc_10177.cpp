#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new int*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new int[n];
            for(int j = 0; j < n; j++) cin >> a[i][j];
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i][i];
        }
        int val = 0;
        for(int i = 0; i < n; i++) {
            val += a[i][n - i - 1];
        } if(sum != val) {
            cout << "Not a magic square\n";
            goto END;
        }
        for(int i = 0; i < n; i++) {
            val = 0;
            for(int j = 0; j < n; j++) {
                val += a[i][j];
            }
            if(sum != val) {
                cout << "Not a magic square\n";
                goto END;
            }
            val = 0;
            for(int j = 0; j < n; j++) {
                val += a[j][i];
            }
            if(sum != val) {
                cout << "Not a magic square\n";
                goto END;
            }
        }
        cout << "Magic square of size " << n << '\n';
    END:for(int i = 0; i < n; i++) delete[] a[i];
        delete[] a;
    }
}