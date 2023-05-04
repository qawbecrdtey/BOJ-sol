#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string tt; getline(cin, tt); int t = stoi(tt); while(t--) {
        string s; getline(cin, s);
        stringstream ss(s);
        string num, op;
        int res = 0;
        vector<int> v;
        ss >> num;
        v.push_back(stoi(num));
        while(ss >> op >> num) {
            if(op == "+") {
                v.push_back(stoi(num));
            }
            else if(op == "-") {
                v.push_back(-stoi(num));
            }
            else if(op == "*") {
                v.back() *= stoi(num);
            }
            else if(op == "/") {
                v.back() /= stoi(num);
            }
            else if(op == "%") {
                v.back() %= stoi(num);
            }
            else __builtin_unreachable();
        }
        for(int now : v) res += now;
        cout << res << '\n';
    }
}