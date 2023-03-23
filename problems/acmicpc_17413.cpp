#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; getline(cin, s);
    bool in_tag = false;
    stack<char> st;
    for(char c : s) {
        if(c == '\0' || c == '\n') break;
        if(c == '>') {
            in_tag = false;
            assert(st.empty());
            cout << '>';
            continue;
        }
        if(in_tag) {
            cout << c;
            continue;
        }
        if(c == ' ') {
            while(!st.empty()) {
                cout << st.top(); st.pop();
            } cout << ' ';
            continue;
        }
        if(c == '<') {
            in_tag = true;
            while(!st.empty()) {
                cout << st.top(); st.pop();
            }
            cout << '<';
            continue;
        }
        st.push(c);
    }
    while(!st.empty()) {
        cout << st.top(); st.pop();
    }
}