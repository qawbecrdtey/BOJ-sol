#include <iostream>
using namespace std;
int main() {
    int n, m, k; cin >> n >> m >> k;
    int v = k - m;
    cout << (n + v - 1) / v;
}