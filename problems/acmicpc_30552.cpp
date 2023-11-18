#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new string[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int idx = 0; bool flag = true;
    while(idx < n) {
        if(idx == n - 1) {
            cout << a[idx];
            flag = false;
            break;
        }
        if(a[idx + 1] == "Present!") idx++;
        else { cout << a[idx] << '\n'; flag = false; }
        idx++;
    }
    if(flag) cout << "No Absences";
}