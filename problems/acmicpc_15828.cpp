#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    queue<int> q;
    while(true) {
        int x; cin >> x; if(x == -1) break;
        if(!x) q.pop();
        else if(q.size() == n) continue;
        else q.push(x);
    }
    while(!q.empty()) { cout << q.front() << ' '; q.pop(); }
}
