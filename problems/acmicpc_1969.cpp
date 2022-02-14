#include <cassert>
#include <iostream>
#include <string>
using namespace std;
inline int f(char c) {
    switch(c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: assert(false);
    }
}
inline char fi(int x) {
    switch(x) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
        default: assert(false);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    auto a = new string[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for(int i = 0; i < m; i++) {
        int arr[4] = {};
        for(int j = 0; j < n; j++) {
            arr[f(a[j][i])]++;
        }
        int resi = 0;
        for(int j = 1; j < 4; j++) {
            if(arr[resi] < arr[j]) resi = j;
        }
        char const c = fi(resi);
        for(int j = 0; j < n; j++) {
            sum += (c != a[j][i]);
        }
        cout << c;
    } cout << '\n' << sum;
}