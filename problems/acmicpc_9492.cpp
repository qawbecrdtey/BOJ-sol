#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
        if(!n) return 0;
        queue<string> v, u;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if(i > (n - 1) / 2) u.push(move(s));
            else v.push(move(s));
        }
        bool b = false;
        while(!v.empty() || !u.empty()) {
            if(b) {
                cout << u.front() << '\n';
                u.pop(); b = false;
            }
            else {
                cout << v.front() << '\n';
                v.pop(); b = true;
            }
        }
    }
}