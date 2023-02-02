#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline vector<int> fibs(int n) {
    vector<int> v{ 1, 1 };
    for(int i = 0; ; i++) {
        int const next = v[i] + v[i + 1];
        if(next > n) break;
        v.push_back(next);
    } return v;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int const m = *max_element(a, a + n);
    auto const fib = fibs(m);
    auto g_num = new int[m + 1]();
    int const fsize = (int)fib.size();
    auto visited = new bool[fsize + 2];
    for(int i = 1; i <= m; i++) {
        fill(visited, visited + fsize + 2, false);
        for(int f : fib) {
            if(i < f) break;
            visited[g_num[i - f]] = true;
        }
        for(int j = 0; j < fsize + 2; j++) {
            if(!visited[j]) {
                g_num[i] = j;
                break;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++) res ^= g_num[a[i]];
    cout << (res ? "koosaga" : "cubelover");
}