#include <iostream>
using namespace std;
inline bool nodup(int n) {
    if(n < 10) return true;
    bool a[10]{};
    while(n) {
        if(a[n % 10]) return false;
        a[n % 10] = true;
        n /= 10;
    } return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[1000001]{};
    for(int i = 1; i <= 1000000; i++) {
        a[i] = a[i - 1] + 1;
        while(!nodup(a[i])) a[i]++;
    }
    int n; while(cin >> n) {
        if(!n) return 0;
        cout << a[n] << '\n';
    }
}