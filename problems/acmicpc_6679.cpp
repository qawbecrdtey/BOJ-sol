#include <iostream>
using namespace std;
inline int sum(int n, int k) {
    int res = 0;
    while(n) {
        res += n % k;
        n /= k;
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 1000; i < 10000; i++) {
        int const ten = sum(i, 10);
        int const twelve = sum(i, 12);
        int const sixteen = sum(i, 16);
        if(ten == twelve && twelve == sixteen) {
            cout << i << '\n';
        }
    }
}