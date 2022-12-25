#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        bool const seven = !(i % 7);
        bool const eleven = !(i % 11);
        if(seven && eleven) cout << "Wiwat!\n";
        else if(seven) cout << "Hurra!\n";
        else if(eleven) cout << "Super!\n";
        else cout << i << '\n';
    }
}