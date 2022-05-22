#include <iostream>
#include <queue>
#include <string>
using namespace std;
inline int l(int a) {
    int const x = a * 10;
    return x % 10000 + x / 10000;
}
inline int r(int a) { return a / 10 + (a % 10) * 1000; }
inline int d(int a) { return (a << 1) % 10000; }
inline int s(int a) { return (a + 9999) % 10000; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        bool visited[10000]{};
        int a, b; cin >> a >> b;
        queue<pair<int, string>> q;
        visited[a] = true;
        q.push({ a, "" });
        while(!q.empty()) {
            auto const [n, str] = q.front(); q.pop();
            if(n == b) {
                cout << str << '\n';
                break;
            }
            if(!visited[l(n)]) visited[l(n)] = true, q.push({ l(n), str + 'L' });
            if(!visited[r(n)]) visited[r(n)] = true, q.push({ r(n), str + 'R' });
            if(!visited[d(n)]) visited[d(n)] = true, q.push({ d(n), str + 'D' });
            if(!visited[s(n)]) visited[s(n)] = true, q.push({ s(n), str + 'S' });
        }
    }
}