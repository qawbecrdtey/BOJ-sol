#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        auto a = new char*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new char[n * 2 - i];
            fill(a[i], a[i] + n * 2 - i - 1, ' ');
            a[i][n * 2 - i - 1] = '\0';
            a[i][i] = a[i][n * 2 - i - 2] = '*';
            cout << a[i] << '\n';
            delete[] a[i];
        } delete[] a;
    }
}