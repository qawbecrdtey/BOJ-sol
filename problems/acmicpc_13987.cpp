#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[6], b[6]; for(int &i : a) cin >> i; for(int &i : b) cin >> i;
    int win{}, tot = 36;
    for(int ai : a) {
        for(int bi : b) {
            win += (ai > bi);
            tot -= (ai == bi);
        }
    } cout.precision(5);
    cout << fixed << (long double)win / tot;

}