#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        int a[9][9]; for(auto &i : a) for(int &j : i) cin >> j;
        for(int i = 0; i < 9; i++) {
            bool visited[10]{};
            for(int j = 0; j < 9; j++) {
                if(visited[a[i][j]]) goto NO;
                visited[a[i][j]] = true;
            }
        }
        for(int i = 0; i < 9; i++) {
            bool visited[10]{};
            for(int j = 0; j < 9; j++) {
                if(visited[a[j][i]]) goto NO;
                visited[a[j][i]] = true;
            }
        }
        for(int p = 0; p < 3; p++) {
            for(int q = 0; q < 3; q++) {
                bool visited[10]{};
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(visited[a[p * 3 + i][q * 3 + j]]) goto NO;
                        visited[a[p * 3 + i][q * 3 + j]] = true;
                    }
                }
            }
        }
        cout << "CORRECT\n";
        continue;
    NO: cout << "INCORRECT\n";
    }
}