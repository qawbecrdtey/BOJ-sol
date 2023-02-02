#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto g_num = new int[n + 1]();
    for(int i = 2; i <= n; i++) {
        vector<int> v;
        for(int j = 0; j <= i / 2 - 1; j++) {
            v.push_back(g_num[j] ^ g_num[i - j - 2]);
        }
        sort(v.begin(), v.end());
        int mex = 0;
        for(int now : v) {
            if(mex == now) mex++;
            else if(mex > now) continue;
            else break;
        } g_num[i] = mex;
    } cout << (g_num[n] ? 1 : 2);
}