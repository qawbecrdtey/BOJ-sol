#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        if(n < 1896 || n % 4) {
            cout << n << " No summer games\n";
            continue;
        }
        if(n == 1916 || n == 1940 || n == 1944) {
            cout << n << " Games cancelled\n";
            continue;
        }
        if(n > 2020) {
            cout << n << " No city yet chosen\n";
            continue;
        }
        cout << n << " Summer Olympics\n";
    }
}