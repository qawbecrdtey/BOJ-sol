#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; priority_queue<int> pq; while(n--) { int x; cin >> x; pq.push(x); }
    int t = 0;
    while(!pq.empty() && t < 1441) {
        if(pq.size() == 1) {
            int x = pq.top(); pq.pop();
            x--; if(x) pq.push(x);
            t++; continue;
        }
        int x = pq.top(); pq.pop(); x--;
        int y = pq.top(); pq.pop(); y--;
        if(x) pq.push(x); if(y) pq.push(y);
        t++;
    } cout << (t <= 1440 ? t : -1);
}