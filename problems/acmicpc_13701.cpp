#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<bool> visited(1<<25);
    int n; while(cin >> n) {
        if(!visited[n]) {
            cout << n << ' ';
            visited[n] = true;
        }
    }
}