#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    if(n < 425) cout << "Violet";
    else if(n < 450) cout << "Indigo";
    else if(n < 495) cout << "Blue";
    else if(n < 570) cout << "Green";
    else if(n < 590) cout << "Yellow";
    else if(n < 620) cout << "Orange";
    else cout << "Red";
}