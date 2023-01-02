#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; int sum = 0;
    for(int i = 1; ; i += 2) {
        sum += i * i;
        if(sum > n) {
            cout << (i >> 1);
            return 0;
        }
    }
}