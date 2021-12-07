#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        bool flag = false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '+') {
                cout << stoi(s.substr(0, i)) + stoi(s.substr(i + 1)) << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << "skipped\n";
    }
}