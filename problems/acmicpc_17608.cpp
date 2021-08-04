#include <stack>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    stack<int> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while(!s.empty() && s.top() <= x) s.pop();
        s.push(x);
    }
    cout << s.size();
}