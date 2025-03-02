#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    double a[10]; double sum = 0; for(auto &i : a) { cin >> i; sum += i; }
    sum /= 10; double var = 0;
    for(auto i : a) var += (sum - i) * (sum - i);
    var /= 9;
    if(var > 1.0000001) cout << "NOT ";
    cout << "COMFY";
}
