#include <iostream>
#include <queue>
#include <utility>
using namespace std;
template<typename T>
inline T &pos(T **a, int n, int m, int k) {
    return a[k / m][k % m];
}
template<typename T>
inline void reset(T const *const *a, T **a_copy, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a_copy[i][j] = a[i][j];
        }
    }
}
inline int bfs(int **a, bool **visited, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] || !a[i][j]) continue;
            queue<pair<int, int>> q;
            q.push({ i, j });
            while(!q.empty()) {
                auto const [x, y] = move(q.front()); q.pop();
                if(visited[x][y]) continue;
                visited[x][y] = true;
                if(x && !visited[x - 1][y]) q.push({ x - 1, y });
                if(y && !visited[x][y - 1]) q.push({ x, y - 1 });
                if(x < n - 1 && !visited[x + 1][y]) q.push({ x + 1, y });
                if(y < m - 1 && !visited[x][y + 1]) q.push({ x, y + 1 });
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += (!visited[i][j]);
        }
    }
    return sum;
}
template<typename T>
inline void print(T const *const *a, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        } cout << '\n';
    } cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    auto a_copy = new int*[n];
    auto visited = new bool*[n];
    auto visited_copy = new bool*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        a_copy[i] = new int[m];
        visited[i] = new bool[m]();
        visited_copy[i] = new bool[m];
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) visited[i][j] = true;
        }
    }
    int max = 0;
    for(int i = 0; i < n * m; i++) {
        if(pos(a, n, m, i)) continue;
        for(int j = i + 1; j < n * m; j++) {
            if(pos(a, n, m, j)) continue;
            for(int k = j + 1; k < n * m; k++) {
                if(pos(a, n, m, k)) continue;
                reset(a, a_copy, n, m);
                reset(visited, visited_copy, n, m);
                pos(a_copy, n, m, i) = pos(a_copy, n, m, j) = pos(a_copy, n, m, k) = 1;
                pos(visited_copy, n, m, i) = pos(visited_copy, n, m, j) = pos(visited_copy, n, m, k) = true;
                int const x = bfs(a_copy, visited_copy, n, m);
                if(max < x) max = x;
            }
        }
    }
    cout << max;
}