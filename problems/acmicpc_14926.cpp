#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const visited = new bool*[n + 1];
    for(int i = 1; i <= n; i++) {
        visited[i] = new bool[n + 1]();
        visited[i][i] = true;
    }
    auto const one_left = [n, visited](int idx) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            cnt += !visited[idx][i];
        } return cnt == 1;
    };
    auto const mini = [n, visited, one_left](int idx) {
        for(int i = 1; i <= n; i++) {
            if(!visited[idx][i]) {
                if(one_left(idx) || !one_left(i)) return i;
            }
        } return n + 1;
    };
    cout << "a1";
    int cur = 1;
    int next;
    while((next = mini(cur)) != n + 1) {
        cout << " a" << next;
        visited[cur][next] = true;
        visited[next][cur] = true;
        cur = next;
    }
}