#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string ress; int resval{};
    int t; cin >> t; while(t--) {
        string s; int val; cin >> s >> val;
        if(resval < val) ress = std::move(s), resval = val;
    } cout << ress;
}