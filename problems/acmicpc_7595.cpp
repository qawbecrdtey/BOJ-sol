#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                cout << '*';
            } cout << '\n';
        }
    }
}