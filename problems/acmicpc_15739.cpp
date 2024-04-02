#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int*[n];
    auto visited = new bool[n * n + 1]();
    for(int i = 0; i < n; i++) {
        a[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(visited[a[i][j]]) {
                cout << "FALSE";
                return 0;
            }
            visited[a[i][j]] = true;
        }
    }
    delete[] visited;
    int const val = n * (n * n + 1) / 2;
    for(int i = 0; i < n; i++) {
        int res = 0;
        int ser = 0;
        for(int j = 0; j < n; j++) {
            res += a[i][j];
            ser += a[j][i];
        }
        if(res != val || ser != val) {
            cout << "FALSE";
            return 0;
        }
    }
    int res = 0, ser = 0;
    for(int i = 0; i < n; i++) {
        res += a[i][i];
        ser += a[i][n - i - 1];
    }
    if(res != val || ser != val) {
        cout << "FALSE";
        return 0;
    }
    cout << "TRUE";
}