#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; bool res = true; string s; while(n--) {
        cin >> s; if(s == "LIE") res = !res;
    } cout << (res ? "TRUTH" : "LIE");
}