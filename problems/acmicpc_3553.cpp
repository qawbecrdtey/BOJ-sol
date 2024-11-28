#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string d; cin >> n >> d; if(d.size() > n) { cout << "No solution."; return 0; }
    cout << d; for(int i = static_cast<int>(d.size()); i < n; i++) cout << '0';
}
