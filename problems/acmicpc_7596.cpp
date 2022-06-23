#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt = 1;
    int n; while(cin >> n) {
        if(!n) return 0;
        auto a = new string[n];
        string s; getline(cin, s);
        for(int i = 0; i < n; i++) {
            getline(cin, a[i]);
        }
        sort(a, a + n);
        cout << tt++ << '\n';
        for(int i = 0; i < n; i++) {
            cout << a[i] << '\n';
        }
        delete[] a;
    }
}