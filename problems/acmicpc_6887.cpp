#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; int i; for(i = 0; i * i <= n; i++); cout << "The largest square has side length " << i - 1 << ".";
}