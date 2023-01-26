#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    bool b = false;
    for(int i = 0; i < 3; i++) {
        string s; cin >> s; if(s != "bubble" && s != "tapioka") b = true, cout << s << ' ';
    } if(!b) cout << "nothing";
}