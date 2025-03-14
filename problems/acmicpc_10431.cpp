#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt; while(tt--) {
        int t; cin >> t;
        vector<int> v;
        int cnt = 0;
        for(int i = 0; i < 20; i++) {
            int x; cin >> x; v.push_back(x);
            for(int j = i; j > 0; j--) {
                if(v[j] < v[j - 1]) {
                    swap(v[j], v[j - 1]);
                    cnt++;
                }
                else break;
            }
        }
        cout << t << ' ' << cnt << '\n';
    }
}
