#define NDEBUG
#pragma GCC optimize("O3")
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; auto a = new int[t];
    for(int i = 0; i < t; i++) cin >> a[i];
    int m = *max_element(a, a + t);
    auto dp = new bool[m]();
    vector<int> squares{ 1 };
    int cur = 2;
    for(int i = 1; i <= m; i++) {
        if(cur * cur == i) {
            squares.push_back(i);
            cur++;
        }
        for(int s : squares) {
            if(!dp[i - s]) {
                dp[i] = true;
                break;
            }
        }
    } for(int i = 0; i < t; i++) cout << (dp[a[i]] ? "koosaga\n" : "cubelover\n");
}