#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b; cin >> n >> a >> b;
    if(a == b) cout << "Anything";
    if(a < b) cout << "Bus";
    if(a > b) cout << "Subway";
}